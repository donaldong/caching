#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <random>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef unsigned int uint;
#define hmap unordered_map
#define hset unordered_set
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define putchar putchar_unlocked

inline int to_int(char *p) {
  int res = 0, i = 0;
  while (p[i] >= '0' && p[i] <= '9') {
    res = res * 10 + p[i++] - '0';
  }
  return res;
}

string rstrip(const char *str, char c) {
    string s(str);
    int i = s.rfind(c);
    if (i < 0) return s;
    return s.substr(0, i);
}

ll get_file_size(ifstream &fs) {
    fs.seekg (0, fs.end);
    ll size = fs.tellg();
    fs.seekg(0, fs.beg);
    return size;
}
