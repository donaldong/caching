#include "common.h"

int main(int argc, char **argv) {
  int size = to_int(argv[1]);
  int k = to_int(argv[2]);
  int* array = new int[size];
  int p;
  while (k--) {
    for (int i = 0; i < size; ++i) {
      p = array[i];
    }
  }
  return 0;
}
