#include "input_controller.hpp"
#include "event_controller.hpp"
// #include "video_controller.hpp"
// #include "world_controller.hpp"

InputController::InputController(  // WorldController& worldController,
                                   // VideoController& videoController,
    EventController& eventController)
    //: worldController(worldController), videoController(videoController), eventController(eventController) {}
    : eventController(eventController) {}

void InputController::pollInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            eventController.raiseEvent("mouse_clicked", {event.button.x, event.button.y});
            // int xVideo = event.button.x;
            // int yVideo = event.button.y;
            // int xWorld;
            // int yWorld;

            // this->videoController.videoCoordToTileCoord(xVideo, yVideo, xWorld, yWorld);

            // World& world = this->worldController.getWorld();
            // world.flipTiletype(xWorld, yWorld);
        }
    }
}
