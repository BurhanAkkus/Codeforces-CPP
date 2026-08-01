#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define MAX_K 25
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>
using namespace std;

array<ll,MAX_N> a,suffixMin,lastSeen;


void solve(){
    ll n;
    cin >> n;
    rep(i,1,n+1,1){
        lastSeen[i] = -1;
    }
    rep(i,0,n,1){
        cin >> a[i];
        lastSeen[a[i]] = i;
    }
    ll msb =  __builtin_clzll(1) - __builtin_clzll(n) + 1;
    suffixMin[n-1] = a[n-1];
    rep(i,2,n + 1,1){
        suffixMin[n-i] = min(suffixMin[n-i+1],a[n-i]);
    }
    ll ans = 0;
    rep(i,0,n,1){
        ans += a[i] - suffixMin[i];
    }
    ll maxim = lastSeen[1];
    ll prev = -1;
    rep(i,1,n + 1,1){
        if(lastSeen[i] < prev) continue;
        maxim = max(maxim,lastSeen[i] - prev - 1);
        prev = lastSeen[i];
    }
    cout << ans + maxim << "\n";
    
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
