#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll a[MAX_N],b[MAX_N];
void solve(){
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> a[i];
    }
    rep(i,0,n,1){
        cin >> b[i];
    }
    ll x=0,y=0,z=0,d=0;
    rep(i,0,n,1){
        if(a[i] == 1 && b[i] == 1){
            x++;
        }
        if(a[i] == 1 && b[i] == 0){
            y++;
        }
        if(a[i] == 0 && b[i] == 1){
            z++;
        }
        if(a[i] == 0 && b[i] == 0){
            d++;
        }
    }
    
    if(y % 2 == 1){
        cout << "1\n";
        return;
    }
    if(y > 0 && y % 2 == 0){
        cout << "2\n";
        return;
    }
    // y == 0
    if(z == 0){
        cout << "0\n";
        return;
    }
    // y == 0 z != 0
    if(x == 0){
        cout << "-1\n";
        return;
    }
    // x > 0 y = 0 z != 0
    if(d > 0){
        cout << "2\n";
        return;
    }
    cout << "-1\n";
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