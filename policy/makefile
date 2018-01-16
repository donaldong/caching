CC = g++ -std=c++11 -O3
size ?= 100
input ?= ../workload/program/data.read.workload

all: lru.o ld.o pivot.o belady.o

lru.o: least-recently-used.cpp
	$(CC) least-recently-used.cpp -o lru.o

ld.o: longest-distance.cpp
	$(CC) longest-distance.cpp -o ld.o

pivot.o: pivot.cpp
	$(CC) pivot.cpp -o pivot.o

belady.o: belady.cpp
	$(CC) belady.cpp -o belady.o

test: belady.o lru.o ld.o pivot.o
	./belady.o $(size) < $(input)
	./lru.o $(size) < $(input)
	./ld.o $(size) < $(input)
	./pivot.o $(size) < $(input)
