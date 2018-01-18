CC = g++ -std=c++11 -O3
size ?= 60

all: lru.o ld.o pivot.o belady.o metrics.out
	cat metrics.out

lru.o: least-recently-used.cpp
	$(CC) least-recently-used.cpp -o lru.o

ld.o: longest-distance.cpp
	$(CC) longest-distance.cpp -o ld.o

pivot.o: pivot.cpp
	$(CC) pivot.cpp -o pivot.o

belady.o: belady.cpp
	$(CC) belady.cpp -o belady.o

metrics.out: metrics.sh
	cd ../workload && make workload
	./metrics.sh $(size) > metrics.out
	cat metrics.out
