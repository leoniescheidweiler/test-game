#include "tile.hpp"

Tile::Tile(int type) {
    this->type = type;
}

const int Tile::getType() {
    return type;
}

void Tile::setType(int type) {
    this->type = type;
}
