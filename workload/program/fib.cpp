#include "common.h"

int fib(int n) {
  if (n <= 1) return 1;
  return fib(n - 2) + fib(n - 1);
}

int main(int argc, char **argv) {
  fib(to_int(argv[1]));
  return 0;
}
