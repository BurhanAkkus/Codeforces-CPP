#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;


void solve(){
    ll n;
    cin >>n;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    vector<ll> c(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> c[i];
    }

    vector<vector<ll>> dp(n+1,vector<ll>(3));
    dp[0][0] = -Infinity;
    dp[0][1] = -Infinity;
    dp[0][2] = -Infinity;
    dp[1][0] = a[1];
    dp[1][1] = -Infinity;
    dp[1][2] = -Infinity;
    for(ll i = 2; i <= n; i++){
        dp[i][0] = dp[i-1][0] + a[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + b[i];
        dp[i][2] = max(dp[i-1][1],dp[i-1][2]) + c[i];
    }
    cout<< dp[n][2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}