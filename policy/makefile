CC = g++ -std=c++11 -O3

all: lru lru ld pivot belady

lru: least-recently-used.cpp
	$(CC) least-recently-used.cpp -o lru.o

ld: longest-distance.cpp
	$(CC) longest-distance.cpp -o ld.o

pivot: pivot.cpp
	$(CC) pivot.cpp -o pivot.o

belady: belady.cpp
	$(CC) belady.cpp -o belady.o
