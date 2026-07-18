#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200005;
const long long MAX_M = 2;
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n),b(n);
    rep(i,0,n,1){
        cin >> a[i];
    }
    rep(i,0,n - 1,1){
        cin >> b[i];
    }
    ll ans = Infinity;
    rep(i,0,m,1){
        ll current = (i - a[0] + m) %m;
        ll lastA = i;
        rep(j,1,n,1){
            current += (b[j-1] - lastA + m - a[j]) %m;
            lastA = (b[j-1] - lastA + m) %m;
        }
        ans = min(ans,current);
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}