#include "input_controller.hpp"
#include "event_controller.hpp"

InputController::InputController(EventController& eventController) : eventController(eventController) {}

void InputController::pollInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            eventController.raiseEvent("mouse_clicked", {event.button.x, event.button.y});
        }
    }
}
