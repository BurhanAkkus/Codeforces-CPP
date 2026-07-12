#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 11
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<array<ll,2>,MAX_N> cards; // cards[i][0] -> i. card A face. cards[i][1] -> i. card B face
ll dp[MAX_N][MAX_K*2];
void solve(){
    ll n,k;
    cin >> n >> k;
    k *=2;
    rep(i,0,n,1){
        cin >> cards[i][0] >> cards[i][1];
    }
    dp[0][0] = cards[0][0];
    dp[0][1] = cards[0][1];
    rep(i,1,n,1){
        dp[i][0] = dp[i-1][0] + cards[i][0];
        rep(j,1,k+1,1){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + cards[i][j%2];
        }
    }
    ll ans = 0;
    rep(i,0,k+1,1){
        ans = max(ans,dp[n-1][i]);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}