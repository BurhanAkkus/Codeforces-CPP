#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200005;
const long long MAX_M = 2;
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll n;
void solve(){
    ll m;
    cin >> n >> m;
    vector<ll> a(n),b(n-1),k(n+1);
    rep(i,0,n,1){
        cin >> a[i];
    }
    rep(i,0,n - 1,1){
        cin >> b[i];
    }
    k[0] = k[n] = 0;
    rep(i,1,n,1){
      k[i] = (b[i] - a[i] - a[i+1] + 2*m) %m;
    }
       // k has n-1 elements: indices 0 .. n-2
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}