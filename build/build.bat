:: WINDOWS BATCH FILE
:: Full-line comment = preceeded by '::'
:: In-line comment = preceeded by '& REM'

@echo off & REM To stop the echo of each command

cls
echo Building Air Route System ...
:: add sleep for 300ms and 1 more echo
timeout /t 1 >nul
echo Compiling source files ...

::   ../src/core/*.cpp ^ //not needed yet, as it's empty for now
::   ../src/frontend/*.cpp ^ //not needed yet, as raylib not implemented yet

g++ -std=c++17 ^
   ../src/main.cpp ^
   ../src/services/*.cpp ^
   ../src/storage/*.cpp ^
   ../src/ui/*.cpp ^
   ../src/utils/*.cpp ^
   -I../include ^
   -o AirRouteSystem.exe

if %ERRORLEVEL% equ 0 (
   echo Build successful!
) else (
   echo Build failed with error code %ERRORLEVEL%.
)

pause
cls