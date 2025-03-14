
#include "TileManager.h"


Tile::Tile(int width, int height) : width(width), height(height) {
    TILE = new unsigned char[width * height]; 
}

Tile::~Tile() {
    delete[] TILE;
}

void Tile::setTILE(const unsigned char* data) {
    for (int i = 0; i < width * height; i++) {
        TILE[i] = data[i];
    }
}

