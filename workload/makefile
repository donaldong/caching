all: default workload metrics.out
	cat metrics.out
	
default:
	cd synthetic && make
	cd program/pintool && make
	cd program && make
	cd metrics && make

.workload.out: config.sh build.sh
	./build.sh
	touch .workload.out

workload: default .workload.out

metrics.out: metrics.sh metrics/metrics.o
	./metrics.sh > metrics.out
