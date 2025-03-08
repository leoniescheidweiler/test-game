#include "debug_controller.hpp"
#include "event_controller.hpp"
#include "game_loop.hpp"
#include "input_controller.hpp"
#include "video_controller.hpp"
#include "world_controller.hpp"

int main() {
    GameLoop gameLoop;

    EventController eventController;
    gameLoop.registerController(&eventController);

    DebugController debugController(eventController);
    gameLoop.registerController(&debugController);

    WorldController worldController(40, 30, eventController);
    gameLoop.registerController(&worldController);

    InputController inputController(eventController);
    gameLoop.registerController(&inputController);

    VideoController videoController(40 * 32, 30 * 32, worldController, eventController);
    gameLoop.registerController(&videoController);

    gameLoop.start();

    return 0;
}
