#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;


void solve(){
    ll n;
    cin >>n;
    ll m;
    cin >> m;
    ll Y;
    cin >> Y;
    vector<vector<pair<ll,ll>>> edges(n + 1, vector<pair<ll,ll>>());
    for(int i = 0; i < m; i++){
        ll a,b,length;
        cin >> a >> b >> length;
        edges[a-1].push_back({b-1, length});
        edges[b-1].push_back({a-1, length});
    }
    vector<ll> X(n, Infinity);
    for(int i = 0; i < n; i++){
        cin >> X[i];
    }
    for(int i = 0; i < n; i++){
        edges[i].push_back({n, X[i]});      
        edges[n].push_back({i, X[i] + Y}); 
    }

    vector<ll> dist(n + 1, Infinity);
    dist[0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]){
            continue;
        }
        for(auto [v, w] : edges[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i < n; i++){
        cout << dist[i] << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}