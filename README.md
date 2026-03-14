# Air Route System
![Latest Tag](https://img.shields.io/github/v/tag/lishacodesgames/AirRoute-System?color=%237DBA84)
![Status Badge](https://img.shields.io/badge/Status-In_Development-yellow)

## Overview
A flight booking — simulator, almost, or system, rather — inspired by boredom and Pinterest :D

This *simulator* lets you pick a flight in multiple ways, book or reject you based on seat availability

### Tech Stack
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) 
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![RayLib](https://img.shields.io/badge/RAYLIB-FFFFFF?style=for-the-badge&logo=raylib&logoColor=black)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)

## How to Clone
`git clone --recursive` to get the raylib submodule local

**If you forgot, do:** <br>
`git submodule update --init --recursive` after regular `git clone`

### Build
```bash
mkdir build
cd build
cmake --preset Release
cmake --build --preset Release
```

*Check out [CMakePresets.json](CMakePresets.json) if you're confused* <br>

Executable will appear in `build/` under preset name

### Linux Dependencies
Raylib requires a lot of libraries that are built-in on Mac and Windows. <br>
No worries, Linux just requires 1 command to install them all:
```bash
sudo apt install \
    libx11-dev \
    libxcursor-dev \
    libxrandr-dev \
    libxi-dev \
    libxinerama-dev \
    libgl1-mesa-dev \
    libasound2-dev \
    libpulse-dev \
    libxkbcommon-dev
```

## Requirements
* CMake 3.20+
* C++ compiler: GCC / Clang
* Ninja (not *required*, but it's what the presets use)