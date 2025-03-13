#include <iostream>
#include <fstream>
#include "Tile.h"

class TileManager {
private:
    vector<vector<Tile>> grid; 
    int gridSize;
    int IMAGE_WIDTH, IMAGE_HEIGHT;
    int emptyX, emptyY; 

public:

    TileManager(int gridSize, int IMAGE_WIDTH, int IMAGE_HEIGHT)
        : gridSize(gridSize), IMAGE_WIDTH(IMAGE_WIDTH), IMAGE_HEIGHT(IMAGE_HEIGHT), emptyX(gridSize-1), emptyY(gridSize-1) {
        grid.resize(gridSize, vector<Tile>(gridSize, Tile(IMAGE_WIDTH/gridSize, IMAGE_HEIGHT/gridSize)));
    }

   
    void generateTiles(const unsigned char* imageData) {
        int tileWidth = IMAGE_WIDTH / gridSize;
        int tileHeight = IMAGE_HEIGHT / gridSize;
        int index = 0;

        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                Tile& tile = grid[i][j];
                unsigned char* tileData = new unsigned char[tileWidth * tileHeight];
                for (int y = 0; y < tileHeight; ++y) {
                    for (int x = 0; x < tileWidth; ++x) {
                        tileData[y * tileWidth + x] = imageData[index++];
                    }
                }
                tile.setTILE(tileData);
                delete[] tileData; 
            }
        }
    }

    
    void makeMove() {
        
        int dx[] = { 0, 1, 0, -1 };  
        int dy[] = { 1, 0, -1, 0 };
        
        
        int direction = rand() % 4;
        int newX = emptyX + dx[direction];
        int newY = emptyY + dy[direction];

        if (newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize) {
            
            swap(grid[emptyX][emptyY], grid[newX][newY]);
            emptyX = newX;
            emptyY = newY;
        }
    }
};
    