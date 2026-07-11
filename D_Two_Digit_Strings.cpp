#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define repRev(i,start,end,decrement) for(ll i=(start);i>(end);i-=(decrement))
const long long MAX_N = 5005;

ll a[MAX_N],b[MAX_N];
ll prefixA[MAX_N],prefixB[MAX_N];

ll dp[MAX_N][MAX_N];
void solve(){
    string sa ,sb;

    cin >> sa >> sb;
    rep(i,0,sa.size(),1){
        a[i] = sa[i] - '0' ;
    }
    ll sizeA = sa.size();
    ll sizeB = sb.size();
    rep(i,0,sb.size(),1){
        b[i] = sb[i] - '0';
    }
    prefixA[0] = 0;
    rep(i,1,sizeA +1,1){
        prefixA[i]= prefixA[i-1] + a[i - 1];
        prefixA[i] %= 10;
    }
    prefixB[0] = 0;
    rep(i,1,sizeB + 1,1){
        prefixB[i] = prefixB[i - 1] + b[i - 1];
        prefixB[i] %= 10; 
    }
    rep(i,0,sizeA + 1,1){
        rep(j,0,sizeB + 1,1){
            dp[i][j] = 0;
        }
    }
    
    rep(i,0,sizeA + 1,1){
        rep(j,0,sizeB + 1,1){
            // a yi skiplemisim
            if(i > 0) dp[i][j] = max(dp[i][j],dp[i-1][j]);
            // b yi skiplemisim
            if(j > 0) dp[i][j] = max(dp[i][j],dp[i][j-1]);
            // a'dan ve b'den i ve j yi almisim.
            if(i > 0 && j > 0 && prefixA[i] == prefixB[j]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
            }
        }
    }
    if(prefixA[sizeA] != prefixB[sizeB]){
        cout << "-1\n";
        return;
    }
    cout << dp[sizeA][sizeB] << "\n";

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
