#ifndef WORLD_CONTROLLER_HPP
#define WORLD_CONTROLLER_HPP

#include "controller.hpp"
#include "world.hpp"

class WorldController : public Controller {
    public:
    WorldController(int width, int height);
    ~WorldController() = default;

    World& getWorld() { return world; }

    void update() override;

    private:
    World world;
};

#endif  // !WORLD_CONTROLLER_HPP
