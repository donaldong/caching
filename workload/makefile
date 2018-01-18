n ?= 100
k ?= 100000
mu ?= 0
sigma ?= 30
x0 ?= 0
gamma ?= 30
fib_n ?= 30
pin = $(PIN_ROOT)/pin

.PHONY: workload
workload:
	cd synthetic && make
	cd program/pintool && make
	cd program && make
	synthetic/random.o $(n) $(k) > random.workload
	synthetic/forward.o $(n) $(k) > forward.workload
	synthetic/rw_normal.o $(n) $(k) $(mu) $(sigma) > rw_normal.workload
	synthetic/rw_cauchy.o $(n) $(k) $(x0) $(gamma) > rw_cauchy.workload
	synthetic/normal.o $(n) $(k) $(sigma) > normal.workload
	$(pin) -t program/pintool/obj-intel64/data.so -o fib -- program/fib.o $(fib_n) 
	$(pin) -t program/pintool/obj-intel64/data.so -o cyclic -- program/cyclic.o $(n) $(k)

.PHONY: metrics
metrics:
	cd metrics && make
	./metrics.sh > metrics.out
	cat metrics.out
