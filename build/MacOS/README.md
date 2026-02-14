# How to Build on Mac

## Run the build.bat file

#### 2 ways to run batch file:
<ol>
   <li> Normal Mode: Will show the files compiling as they compile </li>
   <li> Quick Mode: append " quick" to normal run command to enable quick mode, will skip the outputs and directly compile into AirRouteSystem </li>
</ol>

**Both work just fine. Depends on your patience / trust in your compiler**# How to Build on Mac

## OR just paste this into your terminal to run:
**From Root Repo Directory**
g++ -std=c++17 src/services/*.cpp src/storage/*.cpp src/ui/*.cpp src/utils/*.cpp src/main.cpp -Iinclude -o build/MacOS/AirRouteSystem && "./build/MacOS/AirRouteSystem" "."