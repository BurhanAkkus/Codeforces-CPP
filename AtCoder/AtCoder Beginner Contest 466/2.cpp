#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

void solve(){
    ll n,m;
    cin >> n >> m;
    ll sizeOfColor[101];
    rep(i,0,m + 1,1){
        sizeOfColor[i] = -1;
    }
    rep(i,0,n,1){
        ll c,s;
        cin >> c >> s;
        sizeOfColor[c] = max(sizeOfColor[c],s);
    }
    rep(i,1,m+1,1){
        cout << sizeOfColor[i] << " ";
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}