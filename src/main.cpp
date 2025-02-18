#include "game_loop.hpp"
#include "input_controller.hpp"
#include <iostream>

int main (int argc, char *argv[])
{
    // Create game loop
    GameLoop gameLoop;

    InputController inputController;
    gameLoop.registerController(&inputController);

    gameLoop.start();

    return 0;
}
