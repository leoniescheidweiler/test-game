#include "debug_controller.hpp"
#include <iostream>
#include "event_controller.hpp"

DebugController::DebugController(EventController& eventController) : eventController(eventController) {
    // eventController.registerListener("mouse_clicked", [](const std::vector<int>& args) {
    //     std::cout << "[DEBUG] mouse clicked at " << args[0] << " " << args[1] << std::endl;
    // });

    // eventController.registerListener("tile_clicked", [](const std::vector<int>& args) {
    //     std::cout << "[DEBUG] tile clicked at " << args[0] << " " << args[1] << std::endl;
    // });
}
