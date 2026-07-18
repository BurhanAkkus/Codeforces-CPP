#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


void solve(){
    ll n ,x;
    cin >> n >> x;
    ll a;
    cin >> a; 
    ll tamSigdi = x/a;
    ll siginti = x%a;
    rep(i,0,n-1,1){
        ll a2;
        cin >> a2;
        if(a2 < a){
            tamSigdi *= ((a -1) / a2) + 1;
            tamSigdi += siginti / a2;
            siginti = siginti % a2;
            a = a2;
        }
    }
    cout << tamSigdi + 1 << "\n";
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