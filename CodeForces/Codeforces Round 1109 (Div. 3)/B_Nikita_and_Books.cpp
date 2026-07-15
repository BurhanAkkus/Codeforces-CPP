#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll a[MAX_N];
void solve(){
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> a[i];
    }
     rep(i,0,n,1){
        if(a[i] >= i+1){
            a[i+1] += a[i] - i - 1;
        }
        else{
            cout << "NO\n";
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