#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX


array<bool,105> a;
void solve(){
    ll m,d;
    cin >> m >> d;
    string s;
    cin >> s;
    rep(i,0,m,1){
        if(s[i] == 'G'){
            rep(j,max(0LL,i-d),min(m,i+d + 1),1){
                a[j] = true;
            }
        }
    }
    ll ans = 0;
    rep(i,0,m,1){
        if(!a[i]){
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