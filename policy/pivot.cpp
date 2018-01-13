#include <iostream>
#include <stdio.h>
#include <climits>
#include <unordered_map>
#include <set>
using namespace std;

typedef unsigned long long ull;
#define mp make_pair
#define hmap unordered_map

inline int to_int(char *p) {
  int res = 0, i = 0;
  while (p[i] >= '0' && p[i] <= '9') {
    res = res * 10 + p[i++] - '0';
  }
  return res;
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);  
  int size = to_int(argv[1]);
  int hit = 0, total = 0;
  set<uint> Q;
  uint n;
  uint pivot = 0;
  while (cin >> n) {
    auto itr = Q.find(n);
    if (itr != Q.end()) {
      // Cache Hit: set pivot
      ++hit;
      pivot = *itr;
    } else if (Q.size() == size) {
      // Cache Full: pop the element on the other end of pivot
      if (n > pivot) Q.erase(Q.begin());
      else Q.erase(--Q.end());
    }
    ++total;
    Q.insert(n);
  }
  printf("%d\n%d\n", hit, total);
  return 0;
}
