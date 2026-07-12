// gen.cpp — random tree generator for the DFS + subtree-size drill.
// Usage: gen <seed>  ->  prints a random tree (0-indexed) to stdout.
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    unsigned seed = argc > 1 ? (unsigned)stoul(argv[1]) : 0u;
    mt19937 rng(seed);

    int n = 1 + rng() % 8;                    // small trees: covers n=1..8
    vector<pair<int,int>> edges;
    for (int i = 1; i < n; ++i)               // attach each node to an earlier one
        edges.push_back({(int)(rng() % i), i});

    // relabel so structure isn't always parent<child
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    shuffle(perm.begin(), perm.end(), rng);
    for (auto& e : edges) { e.first = perm[e.first]; e.second = perm[e.second]; }

    // edges are undirected: shuffle endpoint order and edge order
    for (auto& e : edges) if (rng() & 1) swap(e.first, e.second);
    shuffle(edges.begin(), edges.end(), rng);

    cout << n << '\n';
    for (auto& e : edges) cout << e.first << ' ' << e.second << '\n';
    return 0;
}
