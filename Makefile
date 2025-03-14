PGMimage: PGMimage.o TileManager.o Tile.o
	g++ PGMimage.o  TileManager.o Tile.o -o PGMimage

PGMimage.o:
	g++ -c PGMimage.cpp TileManager.cpp Tile.cpp

clean:
	rm *.o PGMimage 

run:
	./PGMimage 3 out.pgm 2 mona512.pgm


