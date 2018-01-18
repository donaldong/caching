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
  hmap<ull, ull> P;
  set<pair<ull, ull>> Q;
  ull p = 0;
  ull n;
  while (cin >> n) {
    auto itr = P.find(n);
    if (itr != P.end()) {
      // Cache Hit: update priority
      ++hit;
      Q.erase(mp(P[n], n));
    } else if (Q.size() == size) {
      // Cache Full: pop front
      P.erase(P.find(Q.begin()->second));
      Q.erase(Q.begin());
      ++miss;
    }
    P[n] = ++p;
    Q.insert(mp(p, n));
  }
  printf("%d %d\n", hit, miss);
  return 0;
}
