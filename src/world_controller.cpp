#include "world_controller.hpp"
#include <iostream>
#include "video_controller.hpp"

WorldController::WorldController(int width, int height) : world(width, height) {
    world.generateRandom();
}

void WorldController::update() {
    // Future: Handle tile updates
}
