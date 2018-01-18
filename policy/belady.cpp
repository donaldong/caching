#include <iostream>
#include <stdio.h>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;

typedef unsigned long long ull;
#define mp make_pair
#define hmap unordered_map
#define hset unordered_set

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
  hmap<ull, queue<int>> D;
  ull n;
  vector<ull> E;
  while (cin >> n) {
    D[n].push(E.size());
    E.push_back(n);
  }
  hset<ull> Q;
  for (int i = 0; i < E.size(); ++i) {
    n = E[i];
    auto itr = Q.find(n);
    if (itr != Q.end()) ++hit;
    else if (Q.size() == size) {
      ull vic, dist = 0;
      for (ull e : Q) {
        while (!D[e].empty() && D[e].front() <= i) D[e].pop();
        if (D[e].empty()) {
          vic = e;
          break;
        } else {
          if (D[e].front() > dist) {
            dist = D[e].front();
            vic = e;
          }
        }
      }
      Q.erase(Q.find(vic));
      ++miss;
    }
    Q.insert(n);
  }
  printf("%d %d\n", hit, miss);
  return 0;
}
