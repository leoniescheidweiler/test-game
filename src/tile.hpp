#ifndef TILE_HPP
#define TILE_HPP

class Tile {
    public:
    Tile(int type);
    ~Tile() = default;

    const int getType();
    void setType(int type);

    private:
    int type;
};

#endif  // !TILE_HPP
