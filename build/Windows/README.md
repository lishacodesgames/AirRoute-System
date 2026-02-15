# How to Build on Windows
Run the build.bat file

#### 2 ways to run batch file:
<ol>
   <li> Normal Mode: Will show the files compiling as they compile </li>
   <li> Quick Mode: append " quick" after batch script's filename to enable quick mode. This will skip the output of detailed steps and directly compile into AirRouteSystem </li>
</ol>

*Both work just fine. Depends on your patience / trust in your compiler*

## OR just paste this into your terminal to run:
Note: after the main compilation command, there must be 2 directories are arguments for main: The executable's location, and the repository's location <br><br>

**From Root Repo Directory** <br>
` g++ -std=c++17 src\services\*.cpp src\storage\*.cpp src\ui\*.cpp src\utils\*.cpp src\main.cpp -Iinclude -o build\Windows\AirRouteSystem && "build\MacOS\AirRouteSystem.exe" "." `
<br><br>

**From build\Windows Directory** <br>
` g++ -std=c++17 ..\..\src\services\*.cpp ..\..\src\storage\*.cpp ..\..\src\ui\*.cpp ..\..\src\utils\*.cpp ..\..\src\main.cpp -I..\..\include -o AirRouteSystem && "AirRouteSystem.exe" "..\.." `