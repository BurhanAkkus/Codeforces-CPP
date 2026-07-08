#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define MAX_N 12

void solve(){
    ll k;
    cin >> k;
    ll sayi = 7;
    rep(i,0,k+1,1){
        if(sayi % k == 0){
            cout << i + 1;
            return;
        }
        sayi = sayi * 10 + 7;
        sayi = sayi % k;
    }
    cout << -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
