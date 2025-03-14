#include "TileManager.h"

TileManager::TileManager(int gridSize, std::string imagePath) {
    pgmImageClass.read(imagePath);
    pgmImageClass.getDims(IMAGE_WIDTH, IMAGE_HEIGHT);
    tileHeight = static_cast<int>(IMAGE_HEIGHT / gridSize); 
    tileWidth = (IMAGE_WIDTH / gridSize);
    buffer = pgmImageClass.getBuffer();
    GRIDSIZE = gridSize;
}

TileManager::~TileManager() {
    for (int i = 0; i < TILES.size(); i++) {
        delete TILES[i];
    }
}

void TileManager::createTiles() {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int k = 0; k < GRIDSIZE; k++) {
            unsigned char* tile_data = new unsigned char[GRIDSIZE * GRIDSIZE];
            for (int w = 0; w < tileHeight; w++) {
                for (int y = 0; y < tileWidth; y++) {
                    int col = k * tileWidth + y;
                    int row = i * tileHeight + w;
                    tile_data[w * tileHeight + y] = buffer[row * IMAGE_WIDTH + col];
                }
            }
            Tile* tile = new Tile(GRIDSIZE, GRIDSIZE);
            tile->setTILE(tile_data);
            TILES.push_back(tile);
        }
    }
    
    unsigned char* tile_data = new unsigned char[GRIDSIZE * GRIDSIZE];
    for (int i = 0; i < GRIDSIZE * GRIDSIZE; i++) {
        tile_data[i] = 0;
    }
    TILES.back()->setTILE(tile_data);
    pgmImageClass.write("see_blocks.pgm");
}
