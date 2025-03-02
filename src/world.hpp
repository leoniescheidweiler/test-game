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

    std::vector<std::vector<Tile>>& getGrid() { return grid; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    bool validTileCoords(int x, int y);

    // Tile& getTile(int x, int y);
    int getTiletype(int x, int y);
    void setTiletype(int x, int y, int type);
    void flipTiletype(int x, int y);

    void generateRandom();

    void printGrid(const std::string& input);

    private:
    int width, height;
    std::vector<std::vector<Tile>> grid;
};

#endif  // !WORLD_HPP
