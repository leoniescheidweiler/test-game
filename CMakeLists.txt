cmake_minimum_required(VERSION 3.16)
project(my_game)

# Set output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Enable C++17 (or later if needed)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# sdl2
find_package(SDL2 REQUIRED)
include_directories(/opt/homebrew/include/SDL2)

# Add source files
add_executable(my_game
    src/main.cpp
    src/world_controller.cpp
    src/world.cpp
    src/video_controller.cpp
)

# Link SDL2
target_link_libraries(my_game PRIVATE ${SDL2_LIBRARIES})
