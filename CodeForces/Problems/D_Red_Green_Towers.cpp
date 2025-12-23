#include <bits/stdc++.h>
using namespace std;

#define ll long long 
ll MOD =  1e9+7;


void solve(){
    ll r;
    cin >> r;
    ll g;
    cin >> g;

    ll h = sqrt(2*(r+g));
    // binary search on h
    while(h*h + h > 2*(r + g)){
        h--;
    }
    vector<vector<ll>> dp(2,vector<ll>(r+1,0));
    //dp[0] => previous round.
    dp[0][0] = 1;
    for(ll i = 1; i <=h; i++){
        // i tek sayiyken 0 -> 1
        // i cift sayiyken 1-> 0 
        for(ll j = 0; j <= r; j++){
            // build the new level from all green blocks
            // check if its valid
            dp[i & 1][j] = 0;
            if(g + j>= (i*i + i)/2){
                dp[i & 1][j] += dp[~i & 1][j];
            }
            //build new level from all red blocks
            // check if its valid
            if(j >= i){
                dp[i & 1][j] += dp[~i & 1][j-i];
            }
            dp[i & 1][j] %= MOD;
        }
    }
    ll sum = 0;
    for(ll i = 0; i <=r; i++){
        sum += dp[h & 1][i];
    }
    cout<< sum % MOD<< "\n";

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
