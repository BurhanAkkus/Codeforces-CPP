#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200005;

vector<vector<ll>> children(MAX_N,vector<ll>());
vector<ll> depth(MAX_N);

ll guildCount(ll root){
  if(children[root].size() == 0){
    return 1;
  }
  ll count = 0;
  for(ll child: children[root]){
    count += guildCount(child);
  }
  if(children[root].size() < 2)
    return count + 1;
  sort(children[root].begin(), children[root].end(), [](ll a, ll b){
    return depth[a] > depth[b];
  });
  return count + depth[children[root][1]] + 1;
}

ll calculateDepth(ll root){
  if(children[root].size() == 0){
    depth[root] = 1;
    return 1;
  }
  ll dep = 0;
  for(ll child:children[root]){
    dep = max(dep,calculateDepth(child));
  }
  depth[root] = dep + 1;
  return depth[root];
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
    depth[i] = 0;
  }
  calculateDepth(1);
  cout << guildCount(1) << "\n";

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
