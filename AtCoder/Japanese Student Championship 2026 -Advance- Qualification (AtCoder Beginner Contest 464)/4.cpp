#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;


void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> x(n);
    vector<ll> y(n-1);
    for( int i = 0; i < n; i++){
        cin >> x[i];
    }
    for( int i = 0; i < n - 1; i++){
        cin >> y[i];
    }
    vector<array<ll, 2>> dp(n);
    // S = 0, R = 1;
    dp[0][0] = s[0] == 'S'? 0 : -x[0];
    dp[0][1] = s[0] == 'R' ? 0 : -x[0];
    for(ll i = 1; i < n; i++){
        // cost of switch + reward
        dp[i][0] = (s[i] == 'S'? 0 : -x[i]) + max(dp[i-1][0] , dp[i-1][1] + y[i-1]);
        dp[i][1] = (s[i] == 'R'? 0 : -x[i]) + max(dp[i-1][0] , dp[i-1][1]);
    }
    cout << max(dp[n-1][0],dp[n-1][1]) << endl;
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