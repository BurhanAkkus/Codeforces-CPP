#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


void solve(){
    ll n;
    cin >> n;
    if( n == 1){
        cout << "1\n";
        return;
    }
    if(n == 2){
        cout << "-1\n";
        return;
    }
    cout << 1 << " " << 2 << " ";
    ll sum = 3;
    rep(i,2,n,1){
        cout << sum << " ";
        sum *=2;
    }
    cout << "\n";
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