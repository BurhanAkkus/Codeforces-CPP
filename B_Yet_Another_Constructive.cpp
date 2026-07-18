#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


void solve(){
    ll n,k,m;
    cin >> n >> k >> m;
    if(k > m){
        cout << "NO\n";
        return;
    } 
    
    cout << "YES\n";
    cout << m-k+1 << " ";
    rep(i,1,n,1){
        cout << "1 ";
    }
    cout << "\n";
    return;

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