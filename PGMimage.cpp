// copyright, Patrick Marais
// Department of Computer Science
// University of Cape Town
// (c) 2025

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "PGMimage.h"

using namespace std;
int gridSize;
string imagePath;
int totalMoves;
int IMAGE_WIDTH ;
int IMAGE_HEIGHT ;
typedef vector<unsigned char> TILE;
vector<TILE> GRID;
void PGMimage::setImageData(unsigned char* data, int wd, int ht)
{
    if (data == nullptr || wd < 1 || ht < 1)
    {
        cerr << "setImageData() invalid data specified - aborted.\n";
        return;
    }
    if (buffer) delete[] buffer;
    buffer = new unsigned char[wd * ht];
    width = wd; height = ht;
    for (size_t i = 0; i < wd * ht; ++i) buffer[i] = data[i];
}
void PGMimage::read(const string& fileName)
{
    ifstream ifs(fileName, ios::binary);
    if (!ifs)
    {
        cerr << "Failed to open file for read: " << fileName << endl;
        return;
    }
    string line;
    ifs >> line >> ws;
    if (line != "P5")
    {
        cerr << "Malformed PGM file - magic is: " << line << endl;
        return;
    }
    while (getline(ifs, line))
    {
        //cout << line << endl;
        if (line[0] != '#') break;
    }
    istringstream iss(line);
    iss >> width >> height;
    //cout << "width, height = (" << width << "," << height << ")\n";

    if (!iss)
    {
        cerr << "Header not correct - unexpected image sizes found: " << line << endl;
        return;
    }
    int maxChan = 0;
    ifs >> maxChan >> ws;
    if (maxChan != 255)
    {
        cerr << "Max grey level incorect - found: " << maxChan << endl;
    }
    // start of binary block

    buffer = new unsigned char[width * height];
    ifs.read(reinterpret_cast<char*>(buffer), width * height);
    
    if (!ifs)
    {
        cerr << "Failed to read binary block - read\n";
    }

    ifs.close();
}

void PGMimage::write(const string& fileName)
{
    if (buffer == nullptr || width < 1 || height < 1)
    {
        cerr << "Invalid data for PGM write to " << fileName << endl;
        return;
    }
    ofstream ofs(fileName, ios::binary);
    if (!ofs)
    {
        cerr << "Unable to open PGM output file " << fileName << endl;
        return;
    }

    ofs << "P5\n#File produced by P Marais\n" << width << " " << height << endl << 255 << endl;
    ofs.write(reinterpret_cast<char*>(buffer), width * height);
    if (!ofs)
    {
        cerr << "Error writing binary block of PGM.\n";
    }

    ofs.close();
}

void promt_user(){
    
    
    cout<<"Enter size of grid: ";
    cin >> gridSize;

    if(gridSize%2 == 0){cerr << "Grid size must be an odd number(e.g 1,3,5,...)"<< endl;exit(0);}
   
    cout<<"Enter image name/path: ";
    cin>>imagePath;
    
    cout<<"Enter number of moves to produce: ";
    cin>>totalMoves;
    


}
void setTiles(){
    int tileWidth = IMAGE_WIDTH / gridSize;
    int tileHeights = IMAGE_HEIGHT / gridSize;


}

int main(){
    
    promt_user();
    PGMimage pgmimage;
    pgmimage.read(imagePath);
    pgmimage.getDims(IMAGE_WIDTH,IMAGE_HEIGHT);

    return 0;
}