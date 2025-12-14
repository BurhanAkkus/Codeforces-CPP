#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 500000;

void solve(){
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    ll ans = 1;
    vector<ll> numbers(n);
    for(ll i = 0; i < n; i++){
        cin >> numbers[i];
        ans *= floor(m / numbers[i]) + 1; 
    }
    cout << ans;



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}