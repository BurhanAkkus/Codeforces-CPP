#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


void solve(){
    ll n;
    cin >> n;
    ll maxim = 0;
    ll ans = 0;
    rep(i,0,n,1){
        char c;
        cin >> c;
        if(c == '#'){
            maxim++;
            ans = max(ans,(maxim+1)/2);
        }
        else{
            maxim = 0;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}