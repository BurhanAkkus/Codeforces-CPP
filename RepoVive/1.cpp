#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
const long long MAX_N = 200000;

vector<ll> a;
vector<ll> b;


void solve(){
    ll n;
    cin >> n;
    a.assign(n+5,0);
    vector<bool> boundary(n,false);
    for(ll i = 0 ; i < n; i++){
        cin >> a[i];
    }
    ll prefixMin = a[0];
    boundary[0] = true;
    for(ll i = 1; i < n; i++){
        if(a[i] <= prefixMin){
            prefixMin = min(prefixMin,a[i]);
            boundary[i] = true;
        }
    }
    ll suffixMax = a[n-1];
    boundary[n-1] = true;
    for(ll i = n -2; i >= 0; i--){
        if(suffixMax <= a[i]){
            suffixMax = max(suffixMax,a[i]);
            boundary[i] = true;
        }
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(boundary[i]){
            ans++;
        }
    }
    cout<< ans << "\n";

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