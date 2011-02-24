# This is just a basic makefile feel free to change this to your liking

all: bfprint bfinterp

bfprint: bfprint.o
	g++ bfprint.o -o bfprint
bfinterp: bfinterp.o
	g++ bfinterp.o -o bfinterp

install:
	cp bfprint /usr/bin
	cp bfinterp /usr/bin

clean:
	rm -rf *.o 
	rm -rf bfinterp bfprint

bfprint.o: bfprint.cpp
bfinterp.o: bfinterp.cpp
