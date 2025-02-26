#include "world.hpp"
#include <random>

World::World(int width, int height) {
    this->width = width;
    this->height = height;

    grid.resize(height, std::vector<Tile>(width, {0}));
}

const Tile& World::getTile(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return grid[y][x];
    }

    throw std::out_of_range("getTile: Coordinates out of bounds");
}

void World::generate() {
    // Random number setup
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    for (auto& row : grid) {
        for (auto& tile : row) {
            tile.type = dist(gen);
        }
    }
}
