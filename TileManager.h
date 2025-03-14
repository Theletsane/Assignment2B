#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "PGMimage.h"

using namespace std;
class TileManager {
private:
    vector<Tile*> TILES ; 
    int IMAGE_WIDTH;
    int IMAGE_HEIGHT;
    PGMimage pgmImageClass;
    int tileHeight;
    int tileWidth;
    const unsigned char* buffer;
public:
    TileManager(int gridSize, string imagePath){
        pgmImageClass.read(imagePath);
        pgmImageClass.getDims(IMAGE_WIDTH,IMAGE_HEIGHT);
        tileHeight = static_cast<int>(IMAGE_HEIGHT/gridSize); 
        tileWidth = static_cast<int>(IMAGE_WIDTH/gridSize);
        buffer = pgmImageClass.getBuffer();
    }

    ~TileManager(){
        for (int i = 0; i< TILES.size();i++){
            delete TILES[i];
        }
       
    }

    void createTiles(){

        for(int i =0; i< gridSize;i++){
            for(int k = 0; k< gridSize;k++){
                unsigned char* tile_data = new unsigned char [gridSize*gridSize];
                for(int w = 0;w<tileHeight;w++){
                    for(int y = 0; y<tileWidth;y++){
                        int col = k*tileWidth + y;
                        int row = i*tileHeight +w;
                        tile_data[w*tileHeight+y] = buffer[row*IMAGE_WIDTH+col];
                    }
                }
                Tile *tile = new Tile(gridSize,gridSize);
                tile->setTILE(tile_data);
                TILES.push_back(tile);
            }
        }

    }


   


    

};

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
    
    
        void displayTile() const {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    cout << (int)TILE[i * width + j] << " ";
                }
                cout << endl;
            }
        }
    };