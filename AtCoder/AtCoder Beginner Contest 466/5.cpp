#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll dp[MAX_N][MAX_K];
ll cards[MAX_N][2];
void solve(){
  ll n,k;
  cin >> n >> k;
  k *=2;
  rep(i,0,n,1){
    cin >> cards[i][0] >> cards[i][1];
  }
  rep(i,0,n,1){
    rep(j,0,k+1,1){
      dp[i][j] = 0;
    }
  }
  dp[0][0] = cards[0][0];
  dp[0][1] = cards[0][1];

  rep(i,1,n,1){
    rep(j,0,k+1,1){
      // flipleme
      dp[i][j] = max(dp[i][j],dp[i - 1][j] + cards[i][j%2]);
      //fliple
      if(j > 0){
        dp[i][j] = max(dp[i][j],dp[i-1][j-1] + cards[i][j%2]);
      }
    }
  }
  ll ans = 0;
  rep(i,0,k+1,1){
    ans = max(ans,dp[n-1][i]);
  }
  cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}