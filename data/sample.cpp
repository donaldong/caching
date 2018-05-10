#include "common.h"

int calc_lis(vector<ull> &arr) {
    int i, j, max = 0, n = arr.size();
        vector<int> lis(n, 1);
    for (i = 0; i < n; ++i) lis[i] = 1;
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
    return max;
}

int main(int argc, char **argv) {
    const char *filename = argv[1];
    int size = to_int(argv[2]);
	ios::sync_with_stdio(false);  
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(0, 1);
    ifstream input(filename, ios::binary|ios::ate);
    input.seekg (0, input.end);
    ll length = input.tellg();
    ll start = (length - size) * dist(e2);
    if (start < 0) start = 0;
    input.seekg(start, input.beg);
	string prefix = rstrip(filename, '.');
	string f1 = prefix + ".data.workload";
	ofstream OUT;
    OUT.open(f1.c_str(), ios::out | ios::binary);
    vector<ull> N(size);
	bool read;
    bool data;
    int reads = 0, writes = 0;
    for (int i = 0; i < size; ++i) {
		input.read((char*)&read, 1);
        if (read) ++reads;
        else ++writes;
        input.read((char*)&N[i], 8);
		OUT.write((char*)&N[i], 8);
	}
	ld abs_diff = 0;
    for (int i = 1; i < size; ++i) {
        ull a = N[i], b = N[i - 1];
        if (a > b) swap(a, b);
        abs_diff += b - a;
    }
	unordered_map<ull, int> t, c;
	ld sum_t = 0;
	for (int i = 0; i < N.size(); ++i) {
		ull n = N[i];
		++c[n];
		if (t.find(n) == t.end()) t[n] = i;
		else {
			sum_t += i;
			sum_t -= t[n];
			t[n] = i;
		}
	}
	ld sum_sqrt_count = 0, sum_count = 0;
	for (auto entry : c) {
	    sum_sqrt_count += sqrt(entry.second);
        sum_count += entry.second;
	}
	int lis = calc_lis(N);
	for (int i = 0; i < size; ++i) {
        N[i] *= -1;
	}
	int nlis = calc_lis(N);
	// num of unique addr
	cout << c.size() << " ";
    cout << reads << " ";
    cout << writes << " ";
	// avg step size
	cout << abs_diff / size << " ";
	// avg reuse distance
	cout << sum_t / size << " ";
	cout << sum_sqrt_count << " ";
	cout << sum_count << " ";
	// LIS
	cout << lis << " ";
	// Negative LIS
	cout << nlis << " "; 
    return 0;
}
