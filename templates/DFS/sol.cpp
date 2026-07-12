// sol.cpp — YOUR drill target.
// Read the tree, root at node 0, print sz[0..n-1] space-separated on one line.
// Parsing is scaffolded (not what you're training). Blank-file the dfs() body
// below and start your clock the moment you begin writing it.
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> sz;

// ---- write your recursive DFS here -------------------------------------
// Set sz[u] = size of the subtree rooted at u (root = 0).
// It's an undirected tree, so guard against walking back into `parent`.
void dfs(int u, int parent) {
    long long subTree = 1;
    for(auto& child: adj[u]){
        if(parent != child){
            dfs(child,u);
            subTree += sz[child];
        }
    }
    sz[u] = subTree;
}
// ------------------------------------------------------------------------

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
