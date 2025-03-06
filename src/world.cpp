#include "world.hpp"
#include <iostream>
#include <random>

World::World(int width, int height) {
    this->width = width;
    this->height = height;

    grid.resize(width, std::vector<Tile>(height, {0}));
}

bool World::validTileCoords(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

int World::getTiletype(int x, int y) {
    if (!validTileCoords(x, y)) {
        throw std::out_of_range("getTiletype: Coordinates out of bounds");
    }
    return grid[x][y].getType();
}

void World::setTiletype(int x, int y, int type) {
    if (!validTileCoords(x, y)) {
        throw std::out_of_range("setTiletype: Coordinates out of bounds");
    }
    grid[x][y].setType(type);
}

void World::flipTiletype(int x, int y) {
    if (!validTileCoords(x, y)) {
        return;
    }

    int type = getTiletype(x, y);
    if (type == 0) {
        setTiletype(x, y, 1);
    } else if (type == 1) {
        setTiletype(x, y, 0);
    }
}

void World::generateRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[x][y].setType(dist(gen));
        }
    }
}

void World::printGrid(const std::string& input) {
    std::cout << input << std::endl;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << grid[x][y].getType();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
