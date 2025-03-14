

#ifndef TILE_H
#define TILE_H

#include <vector>
#include <string>

#include "PGMimage.h"
class Tile {
    private:
    unsigned char *TILE; 
    public:
        
        int width, height;
    
        Tile(int width, int height) ;
    
        ~Tile() ;
    
        void setTILE(const unsigned char* data) ;
};
class TileManager {
private:
    std::vector<Tile*> TILES; 
    int IMAGE_WIDTH;
    int IMAGE_HEIGHT;
    PGMimage pgmImageClass;
    int tileHeight;
    int tileWidth;
    const unsigned char* buffer;
    int GRIDSIZE;

public:
    TileManager(int gridSize, std::string imagePath);
    ~TileManager();
    void createTiles();
};



#endif