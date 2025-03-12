#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Tile class to represent each tile's image data
class Tile {
public:
    unsigned char* TILE; // Pointer to store pixel data for the tile
    int width, height;

    // Constructor to allocate memory for the tile
    Tile(int width, int height) : width(width), height(height) {
        TILE = new unsigned char[width * height]; 
    }

    // Destructor to free the dynamically allocated memory
    ~Tile() {
        delete[] TILE;
    }

    // Copy tile data into this tile
    void setTILE(const unsigned char* data) {
        for (int i = 0; i < width * height; i++) {
            TILE[i] = data[i];
        }
    }

    // Optionally, display or manipulate the tile TILE (for debugging)
    void displayTile() const {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << (int)TILE[i * width + j] << " ";
            }
            cout << endl;
        }
    }
};