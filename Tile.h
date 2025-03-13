#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


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