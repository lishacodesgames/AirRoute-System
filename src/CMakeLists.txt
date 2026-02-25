add_executable(${PROJECT_NAME}
   raylib/buttons.cpp
   services/BookingService.cpp
   services/FlightGenerator.cpp
   storage/FlightStorage.cpp
   storage/PassengerStorage.cpp
   ui/BookingView.cpp
   ui/FlightView.cpp
   ui/Menu.cpp
   ui/PassengerView.cpp
   utils/ParseUtils.cpp
   utils/VectorUtils.cpp
   main.cpp
)
if(WIN32)
   target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/airroute.rc) # AirRoute.exe icon
endif()

add_custom_command( # copies assets/ into build/<Preset>/ to remove dependencies and weird paths in code
   TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_directory
   ${CMAKE_SOURCE_DIR}/assets
   $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
) 

target_precompile_headers(${PROJECT_NAME} PRIVATE
   ${PROJECT_SOURCE_DIR}/include/Precompiled.h
)

add_library(header_only_libs INTERFACE
   ${PROJECT_SOURCE_DIR}/include/core/Flight.h
   ${PROJECT_SOURCE_DIR}/include/core/Passenger.h
)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib header_only_libs)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang") # won't work for MSVC
   target_compile_options(${PROJECT_NAME} PRIVATE
      -Wall
      -Wextra
      -Wpedantic
   )
endif()