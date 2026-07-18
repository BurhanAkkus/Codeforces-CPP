#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<bool> s(n);
    rep(i,0,n,1){
        string s_i;
        cin >> a[i] >> b[i] >> s_i;
        s[i] = s_i == "take";
    }
    ll diff = 0;
    rep(i,0,n,1){
        if(!s[i]){ diff += b[i] - a[i];}
    }
    cout << diff;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}