#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;
vector<vector<ll>> dp(MAX_N,vector<ll>(2));
vector<ll> numberArray(MAX_N,-1);

void solve(){
    ll n;
    cin >> n;

    for(ll i = 0; i < n; i++){
        cin >> numberArray[i];
    }
    vector<vector<ll>> numbersIndices(n + 1);
    dp[0][0] = dp[0][1] = 0;
    for(ll i = 0; i < n; i++){
        numbersIndices[numberArray[i]].push_back(i);
        dp[i][0]  = i > 0? max(dp[i -1][0],dp[i-1][1]) : 0;
        dp[i][1] = 0;

        if(numbersIndices[numberArray[i]].size() >= numberArray[i]){
            dp[i][1] = max(dp[i][0], dp[ numbersIndices[numberArray[i]][numbersIndices[numberArray[i]].size() - numberArray[i]]][0] + numberArray[i]);
        }
    }
    cout << max(dp[n - 1][0],dp[n-1][1]) << '\n';

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
