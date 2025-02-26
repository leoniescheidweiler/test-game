#include "video_controller.hpp"
#include <iostream>
#include "world_controller.hpp"

VideoController::VideoController(int screenWidth, int screenHeight, WorldController& worldController)
    : worldController(worldController) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight,
                              SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // SDL_RaiseWindow(window);
    // SDL_ShowWindow(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

VideoController::~VideoController() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void VideoController::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        }
    }

    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);  // Gray background
    SDL_RenderClear(renderer);

    // Query world for tile data
    const auto& grid = worldController.getWorldGrid();
    int worldWidth = worldController.getWidth();
    int worldHeight = worldController.getHeight();

    for (int y = 0; y < worldHeight; y++) {
        for (int x = 0; x < worldWidth; x++) {
            SDL_Rect rect = {x * tileSize, y * tileSize, tileSize, tileSize};

            if (grid[y][x].type == 0) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // White
            }

            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}
