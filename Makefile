PGMimage: PGMimage.o
	@g++ PGMimage.o -o PGMimage

PGMimage.o:
	@g++ -c PGMimage.cpp

clean:
	@rm *.o PGMimage 

run:
	@./PGMimage


