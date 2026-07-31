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

array<ll,MAX_N> a,indexSums,indexSumsSorted,lastSeen;


void solve(){
    ll n;
    cin >> n;
    rep(i,1,n+1,1){
        indexSums[i] = 0;
        indexSumsSorted[i] = 0;
        lastSeen[i] = -1;
    }
    rep(i,0,n,1){
        cin >> a[i];
        indexSums[a[i]] += i;
        lastSeen[a[i]] = i;
    }
    rep(i,1,n+1,1){
        indexSums[n-i] += indexSums[n-i+1];
    }
    sort(a.begin(), a.begin() + n);
    rep(i,0,n,1){
        indexSumsSorted[a[i]] += i;
    }
    rep(i,1,n,1){
        indexSumsSorted[n-i] += indexSumsSorted[n-i+1];
    }
    ll ans = 0;
    rep(i,1,n+1,1){
        ans += indexSumsSorted[i] - indexSums[i];
    }
    ll maxim = 0;
    rep(i,1,n+1,1){
        if(lastSeen[i] == -1) continue;
        ll cnt = lower_bound(a.begin(), a.begin() + n, i) - a.begin();
        maxim = max(maxim, lastSeen[i] - cnt);
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
