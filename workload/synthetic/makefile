CC = g++ -std=c++11 -O3

all: random.o forward.o rw_normal.o rw_cauchy.o normal.o

random.o: random.cpp
	$(CC) random.cpp -o random.o

forward.o: forward.cpp
	$(CC) forward.cpp -o forward.o

rw_normal.o: rw_normal.cpp
	$(CC) rw_normal.cpp -o rw_normal.o

rw_cauchy.o: rw_cauchy.cpp
	$(CC) rw_cauchy.cpp -o rw_cauchy.o

normal.o: normal.cpp
	$(CC) normal.cpp -o normal.o
