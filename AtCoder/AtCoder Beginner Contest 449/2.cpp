#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX


array<bool,105> a;
void solve(){
    ll h,w,q;
    cin >> h >> w >> q;
    rep(i,0,q,1){
        ll type;
        ll n;
        cin >> type >> n;
        if(type == 1){
            cout << n * w;
            h -= n;
        }
        else{
            cout << n * h;
            w -= n;
        }
        cout << "\n";
    }
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