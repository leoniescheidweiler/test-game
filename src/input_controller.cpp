#include "input_controller.hpp"
#include <iostream>
#include "video_controller.hpp"
#include "world_controller.hpp"

InputController::InputController(WorldController& worldController, VideoController& videoController)
    : worldController(worldController), videoController(videoController) {}

void InputController::pollInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int xVideo = event.button.x;
            int yVideo = event.button.y;
            int xWorld;
            int yWorld;

            this->videoController.videoCoordToTileCoord(xVideo, yVideo, xWorld, yWorld);

            World& world = this->worldController.getWorld();
            world.flipTiletype(xWorld, yWorld);
        }
    }
}
