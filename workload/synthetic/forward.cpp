#include <iostream>
#include <random>
#include <stdio.h>
#include <time.h>
using namespace std;

typedef unsigned long long ull;
typedef long double ld;

int to_int(char *p) {
  int res = 0, i = 0;
  while (p[i] >= '0' && p[i] <= '9') {
    res = res * 10 + p[i++] - '0';
  }
  return res;
}

int main(int argc, char **argv) {
  int n, k;
  n = to_int(argv[1]); k = to_int(argv[2]);
  uint e = 0;
  while (k--) {
    printf("%d\n", (e++) % n);
  }
  return 0;
}