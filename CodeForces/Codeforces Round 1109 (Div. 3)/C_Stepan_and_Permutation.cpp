#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll a[MAX_N];
ll positions[MAX_N];
void solve(){
    ll n,x,y;
    cin >> n >> x >>y;
    ll g = gcd(x,y);
    rep(i,0,n,1){
        cin >> a[i];
        positions[a[i]] = i + 1;
    }
    rep(i,1,n+1,1){
        if((positions[i] - i) % g != 0){
            cout <<"NO\n";
            return;
        }
    }
    cout << "YES\n";
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