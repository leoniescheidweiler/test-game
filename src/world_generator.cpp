#include "world_generator.hpp"
#include <random>

void WorldGenerator::generateRandom(World& world) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    for (int x = 0; x < world.getWidth(); x++) {
        for (int y = 0; y < world.getHeight(); y++) {
            world.getGrid()[x][y].setType(dist(gen));
        }
    }
}

void WorldGenerator::generateRectangle(World& world) {
    for (int x = 0; x < world.getWidth(); x++) {
        for (int y = 0; y < world.getHeight(); y++) {
            world.getGrid()[x][y].setType(1);
        }
    }

    for (int x = 2; x < world.getWidth() - 2; x++) {
        for (int y = 2; y < world.getHeight() - 2; y++) {
            world.getGrid()[x][y].setType(0);
        }
    }
}
