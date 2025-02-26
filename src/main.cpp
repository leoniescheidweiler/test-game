#include <iostream>
#include "game_loop.hpp"
#include "input_controller.hpp"
#include "video_controller.hpp"
#include "world_controller.hpp"

int main() {
    // Create game loop
    GameLoop gameLoop;

    WorldController worldController(16, 9);
    gameLoop.registerController(&worldController);

    // InputController inputController;
    // gameLoop.registerController(&inputController);

    VideoController videoController(640, 480, worldController);
    gameLoop.registerController(&videoController);

    gameLoop.start();

    return 0;
}
