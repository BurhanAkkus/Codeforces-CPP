#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll a[MAX_N],dp[MAX_N][2];
 //dp[i][0] -> i'ye gelene kadar bana izin veren ve benden buyuk sayinin ggegtirdiggi max sum. dp[i][1] -> benden kucuk olup bana izin veren sayinin getirdiggi max sum.
 //i ye gelince, dp[i][0] += a[i]; 

void solve(){
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> a[i];
        dp[i][0]=0;
        dp[i][1]=0;
    }
    dp[0][0]= a[0];
    dp[0][1] = 0;
    if(a[0] + 1 < n){
        if(a[a[0] + 1] < a[0]){
            dp[a[0] + 1][1] += a[0];
        }
        else{
            dp[a[0] + 1][0] += a[0];
        }
    }
    rep(i,1,n,1){
        dp[i][0] += a[i];
        dp[i][1] = max(dp[i][1],dp[i-1][1]);
        if(a[i] + i + 1 < n){
            if(a[a[i] + i + 1] < a[i]){
                dp[a[i] + i + 1][0] = max(dp[a[i] + i + 1][0],dp[i][0]);
            }
            else{
                 dp[a[i] + i + 1][1] = max(dp[a[i] + i + 1][1],dp[i][0]);
            }
        }
    }    
    ll ans = -1;
    rep(i,0,n,1){
        ans = max(dp[i][0],ans);
    }
    cout << ans << "\n";
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
