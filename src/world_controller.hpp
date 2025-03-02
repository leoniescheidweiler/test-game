#ifndef WORLD_CONTROLLER_HPP
#define WORLD_CONTROLLER_HPP

#include "controller.hpp"
#include "event_controller.hpp"
#include "world.hpp"

class WorldController : public Controller {
    public:
    WorldController(int width, int height, EventController& eventController);
    ~WorldController() = default;

    World& getWorld() { return world; }

    void update() override;

    void handleTileClick(const std::vector<int>& args);

    private:
    World world;
    EventController eventController;
};

#endif  // !WORLD_CONTROLLER_HPP
