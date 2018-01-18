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
  int hit = 0, miss = 0;
  set<ull> Q;
  ull n;
  while (cin >> n) {
    auto itr = Q.find(n);
    if (itr != Q.end()) {
      // Cache Hit
      ++hit;
    } else if (Q.size() == size) {
      // Cache Full: pop the element with the longest distance
      int dist_beg = n - *Q.begin();
      auto end = --Q.end();
      int dist_end = *end - n;
      if (dist_beg > dist_end) Q.erase(Q.begin());
      else Q.erase(end);
      ++miss;
    }
    Q.insert(n);
  }
  printf("%d %d\n", hit, miss);
  return 0;
}
