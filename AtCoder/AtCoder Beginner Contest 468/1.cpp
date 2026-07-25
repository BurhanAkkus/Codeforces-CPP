#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX


array<ll,105> a;
void solve(){
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> a[i];
    }
    ll ans = 0;
    rep(i,0,n-2,1){
        if(a[i] < a[i+1] && a[i+1] > a[i+2]){
            ans++;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin >> t;
    while(t--){   
        solve();
    }
}