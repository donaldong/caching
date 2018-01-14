# Caching Policy
### Input
+ Cache size is the only required argument. E.g: `./lru.o 500`
+ Read input from stdin, each element is addressed by an non-negative integer (2^30).
    Elements are sepereted by `'\n'`.
### Belady
+ The optimal policy. Looks into the feature. It becomes slow when the input size and
  the cache size are big.
