inline int to_int(char *p) {
  int res = 0, i = 0;
  while (p[i] >= '0' && p[i] <= '9') {
    res = res * 10 + p[i++] - '0';
  }
  return res;
}
