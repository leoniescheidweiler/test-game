#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

struct Tile {
    int type;
};

class World {
    public:
    World(int width, int height);
    ~World() = default;

    const std::vector<std::vector<Tile>>& getGrid() const { return grid; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    const Tile& getTile(int x, int y) const;

    void generate();

    private:
    int width, height;
    std::vector<std::vector<Tile>> grid;
};

#endif  // !WORLD_HPP
