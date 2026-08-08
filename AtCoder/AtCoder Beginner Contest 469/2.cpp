#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX


void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans=0;
    rep(i,0,n,1){
        if(s[i] == 'x' &&
        (i == 0 || s[i-1] == 'x') &&
        (i == n-1 || s[i+1] == 'x')){
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