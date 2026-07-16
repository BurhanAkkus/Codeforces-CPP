#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 105
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

bool a[MAX_N];
void solve(){
    ll n,k;
    cin >> n >> k;
    rep(i,0,n,1){
        char c;
        cin >> c;
        a[i] = c == 'R';
    }
    if(k * 2 > n){
        cout << "-1\n";
        return;
    }
    ll ans = 0;
    rep(i,0,k,1){
        if(!a[i]){
            ans++;
        }
    }
    rep(i,0,k,1){
        if(a[n-1-i]){
            ans++;
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