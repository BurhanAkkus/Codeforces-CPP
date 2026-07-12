// brute.cpp — trusted O(n^2) oracle for subtree sizes, rooted at node 0.
// Independent of the drill's post-order DFS: BFS to find parents, then for
// every node walk up to the root bumping an ancestor counter. cnt[v] ends
// equal to the size of v's subtree.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    vector<int> par(n, -1);
    vector<char> seen(n, 0);
    queue<int> q; q.push(0); seen[0] = 1;      // root = 0
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int w : adj[u]) if (!seen[w]) { seen[w] = 1; par[w] = u; q.push(w); }
    }
    vector<long long> cnt(n, 0);
    for (int w = 0; w < n; ++w)
        for (int x = w; x != -1; x = par[x]) cnt[x]++;
    for (int i = 0; i < n; ++i) cout << cnt[i] << " \n"[i == n - 1];
    return 0;
}
