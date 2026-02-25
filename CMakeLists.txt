cmake_minimum_required(VERSION 3.20)

project(AirRoute LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99) # raylib
set(CMAKE_CXX_STANDARD 23) # my project
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# disable raylib examples
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(raylib)
add_subdirectory(src)