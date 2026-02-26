add_executable( ${PROJECT_NAME} )
target_sources( ${PROJECT_NAME} PRIVATE
   # todo list .cpp files here
   src/main.cpp
)

add_library(header_only_libs INTERFACE
   include/core/Flight.h
   include/core/Passenger.h
)

target_precompile_headers( ${PROJECT_NAME} PRIVATE include/Precompiled.h )
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib header_only_libs GUI)

# AirRoute.exe icon
if(WIN32)
   target_sources( ${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/airroute.rc )
endif()

# Turn on warnings for GCC and Clang, but not MSVC (which has different warning flags)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
   target_compile_options( ${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic )
endif()

# copy assets/ into build/ to remove dependencies and weird paths in code
add_custom_command(
   TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_directory
         ${CMAKE_SOURCE_DIR}/assets
         $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
) 

# copy text-files/ similar to assets/
add_custom_command(
   TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_directory
         ${CMAKE_SOURCE_DIR}/text-files
         $<TARGET_FILE_DIR:${PROJECT_NAME}>/text-files
)