#include "common.h"

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);  
  int size = to_int(argv[1]);
  const char *filename = argv[2];
  ifstream input(filename, ios::binary|ios::ate);
  ll i = get_file_size(input);
  int hit = 0, miss = 0;
  set<ull> Q;
  ull n;
  ull pivot = 0;
  while (i-- > 0) {
    input.read((char*)&n, 8);
    auto itr = Q.find(n);
    if (itr != Q.end()) {
      // Cache Hit: set pivot
      ++hit;
      pivot = *itr;
    } else if (Q.size() == size) {
      // Cache Full: pop the element on the other end of pivot
      if (n > pivot) Q.erase(Q.begin());
      else Q.erase(--Q.end());
      ++miss;
    }
    Q.insert(n);
  }
  printf("%d %d\n", hit, miss);
  return 0;
}
