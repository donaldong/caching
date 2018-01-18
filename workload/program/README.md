# Virtual Memory Trace Using Pin
### Build Pin Tool
+ `cd pintool`
+ `make`
+ `cd ..`
+ `pin -t pintool/obj-intel64/[PINTOOL].so -- [PROGRAM]`
### Fib
+ arg1 `n`: calculate `fib(n)` using `fib(n) = fib(n - 1) + fib(n - 2)`
### Cyclic
+ arg1 `n`: number of elements
+ arg2 `k`: length of the workload
