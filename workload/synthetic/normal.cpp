#include <iostream>
#include <random>
#include <stdio.h>
#include <random>
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
  ld mu = n, sigma = stold(string(argv[3]));
  mu /= 2;
  default_random_engine gen;
  normal_distribution<ld> dist(mu, sigma);
  while (k--) {
    uint cur = dist(gen);
    cur %= n;
    if (cur < 0) cur += n;
    printf("%d\n", cur);
  }
  return 0;
}
