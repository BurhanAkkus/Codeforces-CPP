#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX

void solve(){
    ll n;
    cin >> n;
    bool allNegative = true;
    rep(i,0,n,1){
        ll a;
        cin >> a;
        allNegative = allNegative && (a<0);
    }
    if(allNegative){
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
    return;
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