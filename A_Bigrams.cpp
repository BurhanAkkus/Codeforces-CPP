#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
const long long MAX_N = 5000;


void solve(){
    ll k;
    cin >> k;
    ll threeCounter = 0;
    ll greaterThan2Counter = 0;
    rep(i,0,k,1){
        ll c;
        cin >> c;
        if(c >= 3){
            threeCounter++;
        }
        if(c >= 2){
            greaterThan2Counter++;
        }
    }
    if(threeCounter > 0){
        cout << "YES\n";
        return;
    }
    if(greaterThan2Counter > 1){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
