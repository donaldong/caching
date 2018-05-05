CC = g++ -std=c++11 -O3
size ?= 60

all: lru.o mru.o ld.o pivot.o belady.o

lru.o: least-recently-used.cpp
	$(CC) least-recently-used.cpp -o lru.o

mru.o: most-recently-used.cpp
	$(CC) most-recently-used.cpp -o mru.o

ld.o: longest-distance.cpp
	$(CC) longest-distance.cpp -o ld.o

pivot.o: pivot.cpp
	$(CC) pivot.cpp -o pivot.o

belady.o: belady.cpp
	$(CC) belady.cpp -o belady.o

clean:
	rm *.o
