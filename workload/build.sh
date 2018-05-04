#!/bin/bash
source config.sh
synthetic/random.o $n $k > random.workload
synthetic/forward.o $n $k > forward.workload
synthetic/rw_normal.o $n $k $mu $sigma > rw_normal.workload
synthetic/rw_cauchy.o $n $k $x0 $gamma > rw_cauchy.workload
synthetic/normal.o $n $k $sigma > normal.workload
$pin -t program/pintool/obj-intel64/log.so -o fib -- program/fib.o $fib_n 
$pin -t program/pintool/obj-intel64/log.so -o cyclic -- program/cyclic.o $n $k
