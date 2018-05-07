#include "common.h"

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);  
  int size = to_int(argv[1]);
  const char *filename = argv[2];
  ifstream input(filename, ios::binary|ios::ate);
  ll i = get_file_size(input);
  i /= 8;
  int hit = 0, miss = 0;
  set<ull> Q;
  ull n;
  while (i-- > 0) {
    input.read((char*)&n, 8);
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
