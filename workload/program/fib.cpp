int fib(int n) {
  if (n <= 1) return 1;
  return fib(n - 2) + fib(n - 1);
}

inline int to_int(char *p) {
  int res = 0, i = 0;
  while (p[i] >= '0' && p[i] <= '9') {
    res = res * 10 + p[i++] - '0';
  }
  return res;
}

int main(int argc, char **argv) {
  fib(to_int(argv[1]));
  return 0;
}
