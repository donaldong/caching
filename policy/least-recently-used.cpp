#include "common.h"
#include <fstream>

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);  
    int size = to_int(argv[1]);
    const char *filename = argv[2];
    ifstream input(filename, ios::binary|ios::ate);
    input.seekg (0, input.end);
    ll length = input.tellg();
    input.seekg (0, input.beg);
    int hit = 0, miss = 0;
    hmap<ull, ull> P;
    set<pair<ull, ull>> Q;
    ull p = 0;
    ull n;
    length /= 10;
    bool read;
    bool data;
    while (length >= 0) {
        --length;
        input.read((char*)&read, 1);  
        input.read((char*)&data, 1);  
        input.read((char*)&n, 8);  
        auto itr = P.find(n);
        if (itr != P.end()) {
            // Cache Hit: update priority
            ++hit;
            Q.erase(mp(P[n], n));
        } else if (Q.size() == size) {
            // Cache Full: pop front
            P.erase(P.find(Q.begin()->second));
            Q.erase(Q.begin());
            ++miss;
        }
        P[n] = ++p;
        Q.insert(mp(p, n));
    }
    printf("%d %d\n", hit, miss);
    return 0;
}
