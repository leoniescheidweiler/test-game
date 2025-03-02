#include <iostream>
#include <vector>
#include "debug_controller.hpp"
#include "event_controller.hpp"
#include "game_loop.hpp"
#include "input_controller.hpp"
#include "video_controller.hpp"
#include "world_controller.hpp"

int main() {
    // Create game loop
    GameLoop gameLoop;

    EventController eventController;
    gameLoop.registerController(&eventController);

    DebugController debugController(eventController);
    gameLoop.registerController(&debugController);

    WorldController worldController(16, 9, eventController);
    gameLoop.registerController(&worldController);

    InputController inputController(eventController);
    gameLoop.registerController(&inputController);

    VideoController videoController(640, 480, worldController, eventController);
    gameLoop.registerController(&videoController);

    gameLoop.start();

    return 0;
}
