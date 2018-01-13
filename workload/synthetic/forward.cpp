#include <iostream>
#include <random>
#include <stdio.h>
#include <time.h>
using namespace std;

typedef unsigned long long ull;
typedef long double ld;

ull __MAX;

ld __RAND() {
  ull r = rand();
  r <<= 15;
  r += rand();
  ld res = r;
  res /= __MAX;
  return res;
}

int to_int(char *p) {
  int res = 0, i = 0;
  while (p[i] >= '0' && p[i] <= '9') {
    res = res * 10 + p[i++] - '0';
  }
  return res;
}

int main(int argc, char **argv) {
  __MAX = RAND_MAX;
  __MAX <<= 15;
  __MAX += RAND_MAX;
  srand(time(0));
  int n, k;
  n = to_int(argv[1]); k = to_int(argv[2]);
  while (k--) {
    int p = n * __RAND();
    printf("%d\n", p);
  }
  return 0;
}
