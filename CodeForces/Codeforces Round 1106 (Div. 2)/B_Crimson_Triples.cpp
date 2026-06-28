#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200005

void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ans += (n/i) * (n/i);
    }
    cout << ans << "\n";

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
