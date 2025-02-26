#ifndef WORLD_CONTROLLER_HPP
#define WORLD_CONTROLLER_HPP

#include "controller.hpp"
#include "world.hpp"

class WorldController : public Controller {
    public:
    WorldController(int width, int height);
    ~WorldController() = default;

    const std::vector<std::vector<Tile>>& getWorldGrid() const { return world.getGrid(); }
    int getWidth() const { return world.getWidth(); }
    int getHeight() const { return world.getHeight(); }

    void update() override;

    private:
    World world;
};

#endif  // !WORLD_CONTROLLER_HPP
