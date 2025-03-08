#include "world_controller.hpp"
#include "event_controller.hpp"

WorldController::WorldController(int width, int height, EventController& eventController)
    : world(width, height), eventController(eventController) {
    eventController.registerListener("tile_clicked",
                                     std::bind(&WorldController::handleTileClick, this, std::placeholders::_1));
    world.generate();
}

void WorldController::update() {}

void WorldController::handleTileClick(const std::vector<int>& args) {
    world.flipTiletype(args[0], args[1]);
}
