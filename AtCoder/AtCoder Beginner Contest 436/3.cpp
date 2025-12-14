#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    //vector n by n
    ll m;
    cin >> m;
    set<pair<ll,ll>> blocks;
    ll ans = 0;
    for(ll i = 0; i < m; i++){
        ll r;
        cin >> r;
        ll c;
        cin >> c;
        if(!blocks.contains({r,c}) && !blocks.contains({r,c+1}) && !blocks.contains({r+1,c}) && !blocks.contains({r+1,c+1}))
        {
            blocks.insert({r,c});
            blocks.insert({r+1,c});
            blocks.insert({r,c+1});
            blocks.insert({r+1,c+1});
            ans++;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}