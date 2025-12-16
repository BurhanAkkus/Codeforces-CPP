#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
const long long MAX_N = 200000;

vector<ll> a;
void solve(){
    ll n;
    cin >> n;
    a.assign(n+5,0);
    for(ll i = 0 ; i < n; i++){
        cin >> a[i];
    }

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