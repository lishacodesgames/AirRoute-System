add_library(GUI STATIC)
target_sources(GUI PRIVATE
   src/Button.cpp
   src/raygui.c
)

target_include_directories(GUI PUBLIC include)
target_link_libraries(GUI PUBLIC raylib)

# Turn off raygui warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
   set_source_files_properties( src/raygui.c PROPERTIES COMPILE_OPTIONS "-w" )
endif()