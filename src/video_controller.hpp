#ifndef VIDEO_CONTROLLER_HPP
#define VIDEO_CONTROLLER_HPP

#include <SDL.h>
#include "controller.hpp"
#include "world_controller.hpp"

class VideoController : public Controller {
    public:
    VideoController(int screenWidth, int screenHeight, WorldController& worldController);
    ~VideoController();

    void update() override;
    void videoCoordToTileCoord(int xVideo, int yVideo, int& xTile, int& yTile);

    private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int tileSize = 32;
    WorldController& worldController;
};

#endif  // !VIDEO_CONTROLLER_HPP
