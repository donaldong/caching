#include "common.h"

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
    hset<ull> S;
	string prefix = rstrip(filename, '.');
	string outfile = prefix + ".comb.workload";
	ofstream OUT;
    OUT.open(outfile.c_str(), ios::out | ios::binary);

	ull n;
	bool read;
    bool data;
	while (size-- > 0) {
		input.read((char*)&read, 1);  
        input.read((char*)&data, 1);  
        input.read((char*)&n, 8);  
		OUT.write((char*)&n, 8);
		S.insert(n);
	}
	printf("%ld\n", S.size());
    return 0;
}
