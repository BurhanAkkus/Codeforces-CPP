#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD   998244353
const long long MAX_N = 200000;

vector<ll> nodes(static_cast<size_t>(MAX_N) + 5);

void solve(){
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vector<pair<ll,ll>> edges;
    edges.reserve(static_cast<size_t>(m));
    vector<map<ll,ll>> dp(n);
    for(ll i = 0; i < n; i++){
        cin >> nodes[i];
    }
    for(ll i = 0; i <  m ; i++){
        ll source;
        cin >> source;
        source--;
        ll destination;
        cin >> destination;
        destination--;
        edges.emplace_back(source,destination);
    }
    sort(edges.begin(), edges.end(), [&](const pair<ll,ll> &a, const pair<ll,ll> &b){
        return  (nodes[a.first] + nodes[a.second]) > (nodes[b.first] + nodes[b.second]);
    });
    for(ll i = 0; i < m; i++){
        pair<ll,ll> edge = edges[i];
        ll source = edge.first;
        ll destination = edge.second;
    }

    // dp
    for(ll currentEdgeIndex = 0; currentEdgeIndex < m; currentEdgeIndex++){
        pair<ll,ll> currentEdge = edges[currentEdgeIndex];
        ll source = currentEdge.first;
        ll destination = currentEdge.second;
        auto &target = dp[source][nodes[destination]];
        auto it = dp[destination].find(nodes[source] + nodes[destination]);
        if(it != dp[destination].end()){
            target += it->second;
            if(target >= MOD) target %= MOD;
        }
        target += 1;
        if(target >= MOD) target -= MOD;
    }

    ll ans = 0;
    for(const auto &row : dp){
        for(const auto &entry : row){
            ans += entry.second;
            if(ans >= MOD) ans -= MOD;
        }
    }
    cout << ans % MOD << "\n";



}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
