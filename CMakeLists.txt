cmake_minimum_required(VERSION 3.16)
project(my_game)

# Set output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Enable C++17 (or later if needed)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find godot-cpp bindings
set(GODOT_CPP_PATH /Users/leonie/dev/godot-cpp)
set(GODOT_CPP_LIB_PATH ${GODOT_CPP_PATH}/bin)

# Include the Godot C++ binding headers
include_directories(${GODOT_CPP_PATH}/include)

# Link the release version of the library
set(GODOT_CPP_LIB "${GODOT_CPP_LIB_PATH}/libgodot-cpp.macos.template_release.universal.a")

# Add source files
add_library(my_game MODULE src/game_loop.cpp)

# Link against Godot C++ bindings
target_link_libraries(my_game PRIVATE ${GODOT_CPP_LIB})
