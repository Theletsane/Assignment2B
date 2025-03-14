#ifndef TILE_H
#define TILE_H

class Tile {
public:
    unsigned char* TILE; 
    int width, height;

    Tile(int width, int height) : width(width), height(height) {
        TILE = new unsigned char[width * height]; 
    }

    ~Tile() {
        delete[] TILE;
    }

    void setTILE(const unsigned char* data) {
        for (int i = 0; i < width * height; i++) {
            TILE[i] = data[i];
        }
    }
};

#endif // TILE_H
