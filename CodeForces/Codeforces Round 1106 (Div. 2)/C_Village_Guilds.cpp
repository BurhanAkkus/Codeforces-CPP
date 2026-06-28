#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200005;


vector<ll> depth(MAX_N);
vector<vector<ll>> children(MAX_N);

ll guildCount(int root){
    if(children[root].size() == 0){
        return 1;
    }
    ll count = 0;
    for(ll child:children[root]){
        count += guildCount(child);
    }
    sort(children[root].begin(), children[root].end(), [](ll a, ll b){
        return depth[a] > depth[b];
    });
    return count + 1 + (children[root].size() > 1 ? depth[children[root][1]] : 0);
} 


ll calculateDepth(int root){
    if(children[root].size() == 0){
        depth[root] = 1;
        return 1;
    }
    ll dep = 0;
    for(int child:children[root]){
        dep = max(dep,calculateDepth(child));
    }
    depth[root] = dep + 1;
    return dep + 1;
}

void solve(){
    ll n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        children[i].clear();
        depth[i] = 0;
    }
    for(int i = 2; i <= n; i++){
        ll parent;
        cin >> parent;
        children[parent].push_back(i);
    }
    calculateDepth(1);
    cout << guildCount(1) << endl;

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
