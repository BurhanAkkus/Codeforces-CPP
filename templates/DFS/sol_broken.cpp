// sol_broken.cpp — DELIBERATELY WRONG. Sabotage check for your harness.
// Run the driver against THIS first: it MUST report a mismatch. If it
// "passes", the harness is broken, not the solution — fix the harness
// before you trust any green result from your real sol.cpp.
// Bug: starts the count at 0 instead of 1 (forgets to count the node itself).
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> sz;

void dfs(int u, int parent) {
    sz[u] = 0;                                   // BUG: should be 1
    for (int v : adj[u]) if (v != parent) { dfs(v, u); sz[u] += sz[v]; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> n)) return 0;
    adj.assign(n, {});
    sz.assign(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) cout << sz[i] << " \n"[i == n - 1];
    return 0;
}
