:: WINDOWS BATCH FILE
:: TESTED base ✔
:: TESTED raylib X (not implemented yet, so no build errors, but also no graphics)

:: !! NOTE: NO FOLDER IN BASE PATH SHOULD HAVE SPACE IN THEM, IT WILL BREAK THE BUILD 

:: To stop the echo of each command (VERY IMPORTANT)
@echo off
setlocal EnableDelayedExpansion



:: -----------------
:: DETECT LOCATIONS
:: -----------------

:: get script directory
set "SCRIPT_DIR=%~dp0"
:: remove trailing backlash cuz we are appending \ anyways
set "SCRIPT_DIR=%SCRIPT_DIR:~0,-1%"
:: currently in Windows\, go up ..\.. to root repo
set "BASE=%SCRIPT_DIR%\..\.."

:: Normalise path (it is relative rn, which is dangerous)
for %%i in ("%BASE%") do set "BASE=%%~fi"

if not exist "%BASE%\src\main.cpp" (
   echo Error: main.cpp not found in src directory.
   exit /b 1
)

:: Set output executable name & location
set "OUT=%BASE%\build\Windows\AirRouteSystem.exe"
if exist "%OUT%" (
   rm %OUT%
)

cls
echo Building Air Route System
echo Project Directory: "%BASE%"
echo Output File: "%OUT%"

:: -----------
:: QUICK MODE
:: -----------
set "MODE=%1"
if "%MODE%"=="quick" (
   echo.
   echo QUICK MODE ENABLED: skipping detailed compilation steps.
   g++ -std=c++17 ^
      %BASE%\src\services\*.cpp ^
      %BASE%\src\storage\*.cpp ^
      %BASE%\src\ui\*.cpp ^
      %BASE%\src\utils\*.cpp ^
      %BASE%\src\main.cpp ^
      -I%BASE%\include -o %OUT%

   if %ERRORLEVEL% equ 0 (
      cls
      echo Build successful in quick mode!
      exit /b 0
   ) else (
      echo.
      echo Build failed in quick mode with error code %ERRORLEVEL%.
      exit /b 1
   )
)

:: ../src/core/*.cpp   not needed yet, as it's empty for now
:: ../src/frontend/*.cpp   not needed yet, as raylib not implemented yet

:: ----------
:: COMPILING
:: ----------

:: make obj folder
set "OBJ_DIR=%BASE%\build\Windows\obj"
if exist "%OBJ_DIR%" (
   rmdir /s /q "%OBJ_DIR%"
   if exist "%OBJ_DIR%" (
      echo failed to remove existed build\Windows\obj\ directory!
   )   
)
mkdir "%OBJ_DIR%"

:: temporarily make current directory = obj to contain *.o
pushd "%OBJ_DIR%"

echo.
echo ----------SERVICES----------
for %%f in (%BASE%\src\services\*.cpp) do (
   :: print only filename without path
   echo Compiling %%~nxf...
)
g++ -std=c++17 -c %BASE%\src\services\*.cpp -I%BASE%\include
if %ERRORLEVEL% neq 0 (
   echo Compilation failed for services with error code %ERRORLEVEL%.
   popd
   exit /b 1
)

echo.
echo ----------STORAGE----------
for %%f in (%BASE%\src\storage\*.cpp) do (
   echo Compiling %%~nxf...
)
g++ -std=c++17 -c %BASE%\src\storage\*.cpp -I%BASE%\include
if %ERRORLEVEL% neq 0 (
   echo Compilation failed for storage with error code %ERRORLEVEL%.
   popd
   exit /b 1
)

echo.
echo ----------UI----------
for %%f in (%BASE%\src\ui\*.cpp) do (
   echo Compiling %%~nxf...
)
g++ -std=c++17 -c %BASE%\src\ui\*.cpp -I%BASE%\include
if %ERRORLEVEL% neq 0 (
   echo Compilation failed for ui with error code %ERRORLEVEL%.
   popd
   exit /b 1
)

echo.
echo ----------UTILS----------
for %%f in (%BASE%\src\utils\*.cpp) do (
   echo Compiling %%~nxf...
)
g++ -std=c++17 -c %BASE%\src\utils\*.cpp -I%BASE%\include
if %ERRORLEVEL% neq 0 (
   echo Compilation failed for utils with error code %ERRORLEVEL%.
   popd
   exit /b 1
)

:: MAIN
cls
echo Compiling MAIN
g++ -std=c++17 -c %BASE%\src\main.cpp -I%BASE%\include
if %ERRORLEVEL% neq 0 (
   echo Compilation failed for main.cpp with error code %ERRORLEVEL%.
   popd
   exit /b 1
)

:: -------------------------------
:: Creating .exe and deleting *.o
:: -------------------------------
echo.
echo Linking object files...
g++ *.o -o "%OUT%"

:: go back to working directory
popd
rmdir /s /q "%OBJ_DIR%"

if %ERRORLEVEL% equ 0 (
   echo.
   echo Build successful!!
   echo.
   echo Tap any key to run program . . .
   pause >nul

   :: 2 args to run program: .exe, root path for storage access
   "%OUT%" "%BASE%"
) else (
   echo.
   echo Build failed with error code %ERRORLEVEL%.
)

pause