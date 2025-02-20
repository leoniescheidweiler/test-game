#include "world_controller.hpp"
#include <iostream>

WorldController::WorldController(int width, int height) :
    world(width, height)
{
    world.generate();
}

void WorldController::update(){
    // Future: Handle tile updates
    std::cout << "World updated." << std::endl;
}
