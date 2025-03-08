#ifndef WORLD_GENERATOR_HPP
#define WORLD_GENERATOR_HPP

#include "world.hpp"

class WorldGenerator {
    public:
    static void generateRandom(World& world);
    static void generateRectangle(World& world);
};

#endif  // !WORLD_GENERATOR_HPP
