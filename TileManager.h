#include <iostream>
#include <fstream>
class TileManager {
private:
    vector<vector<Tile>> grid; // 2D grid to hold the tiles
    int gridSize;
    int IMAGE_WIDTH, IMAGE_HEIGHT;
    int emptyX, emptyY; // Coordinates of the empty space

public:
    // Constructor to initialize the grid size, image width and height
    TileManager(int gridSize, int IMAGE_WIDTH, int IMAGE_HEIGHT)
        : gridSize(gridSize), IMAGE_WIDTH(IMAGE_WIDTH), IMAGE_HEIGHT(IMAGE_HEIGHT), emptyX(gridSize-1), emptyY(gridSize-1) {
        grid.resize(gridSize, vector<Tile>(gridSize, Tile(IMAGE_WIDTH/gridSize, IMAGE_HEIGHT/gridSize)));
    }

    // Method to generate the tiles from the image data
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
                tile.setPixels(tileData);
                delete[] tileData; // Free temporary memory after assigning
            }
        }
    }

    // Method to perform a random move
    void makeMove() {
        // Randomly select an adjacent tile to swap with the empty space
        int dx[] = { 0, 1, 0, -1 };  // Right, Down, Left, Up
        int dy[] = { 1, 0, -1, 0 };
        
        // Randomly choose a direction for the move
        int direction = rand() % 4;
        int newX = emptyX + dx[direction];
        int newY = emptyY + dy[direction];

        if (newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize) {
            // Swap the empty space with the tile at (newX, newY)
            swap(grid[emptyX][emptyY], grid[newX][newY]);
            emptyX = newX;
            emptyY = newY;
        }
    }

    // Method to output the current state as a PGM image
    void outputImage(const string& filename) {
        ofstream file(filename, ios::binary);
        file << "P5" << endl;
        file << IMAGE_WIDTH << " " << IMAGE_HEIGHT << endl;
        file << "255" << endl;

        unsigned char* imageData = new unsigned char[IMAGE_WIDTH * IMAGE_HEIGHT];
        int index = 0;
        
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                const Tile& tile = grid[i][j];
                for (int y = 0; y < tile.height; ++y) {
                    for (int x = 0; x < tile.width; ++x) {
                        imageData[index++] = tile.pixels[y * tile.width + x];
                    }
                }
            }
        }

        file.write(reinterpret_cast<char*>(imageData), IMAGE_WIDTH * IMAGE_HEIGHT);
        delete[] imageData;
    }
};
    