
#include "TileManager.h"


Tile::Tile(int width, int height) {
    std::cout <<"Im in tile1"<< std::endl;
    TILE = new unsigned char[static_cast<int> (width * height)]; 
    std::cout <<"Im in tile2"<< std::endl;
    
}

Tile::~Tile() {
    delete[] TILE;
}

void Tile::setTILE(const unsigned char* data) {
    for (int i = 0; i < width * height; i++) {
        TILE[i] = data[i];
    }
}

