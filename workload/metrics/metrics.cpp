#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long double ld;

int main() {
  vector<ull> N;
  ull n;
  while (cin >> n) {
    N.push_back(n);
  }
  ld sum_diff = 0;
  for (int i = 1; i < N.size(); ++i) {
    ld diff  = N[i];
    diff -= N[i - 1];
    sum_diff += abs(diff);
  }
  unordered_map<ull, int> t, c;
  ld sum_t = 0;
  for (int i = 0; i < N.size(); ++i) {
    n = N[i];
    ++c[n];
    if (t.find(n) == t.end()) t[n] = i;
    else {
      sum_t += i;
      sum_t -= t[n];
      t[n] = i;
    }
  }
  ld sum_sqrt_count = 0;
  for (auto entry : c) {
    sum_sqrt_count += sqrt(entry.second);
  }
  // Fractional Uniqueness
  cout << double(c.size()) / N.size() << " ";
  // Average square-root of frequencies
  cout << sum_sqrt_count / c.size() << " ";
  // Average reuse distance
  cout << sum_t / N.size() << " ";
  // Average Normalized step size
  cout << sum_diff / N.size() << endl;
  return 0;
}
