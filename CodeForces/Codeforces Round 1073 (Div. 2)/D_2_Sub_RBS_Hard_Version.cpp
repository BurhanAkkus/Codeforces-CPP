#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
const long long MAX_N = 100;

vector<char> numberArray(MAX_N+5,-1);




        // if(numberArray[i] == ')'){
        //     for(ll charSayisi = n; charSayisi > 0; charSayisi--){
        //         for(ll runningSum = n; runningSum > 0; runningSum--){
                    
        //         }
        //     }
        // }
void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    vector<vector<vector<ll>>> dp(
    4,
    vector<vector<ll>>(MAX_N + 1, vector<ll>((MAX_N)/2 + 2, 0))
);
    for(ll i = 0; i < n; i++){
        cin >> numberArray[i];
    }
    for(ll i = 0; i < n; i++){
        if(numberArray[i] == ')'){
       
        // STATE 4
         // cevaba gecis
            for(ll charSayisi = 2; charSayisi <= n; charSayisi++){
                ans += (dp[3][charSayisi][1] * (charSayisi - 1))% MOD;
                ans %= MOD;
            }
         // Self feed
            for(ll charSayisi = n - 1; charSayisi > 3; charSayisi--){
                for(ll runningSum = 2; runningSum < n/2+2; runningSum++){
                    dp[3][charSayisi+1][runningSum - 1] += dp[3][charSayisi][runningSum];
                    dp[3][charSayisi+1][runningSum - 1] %= MOD;
                }
            }
        //STATE 2
            //self Feed
            for(ll charSayisi = n - 1; charSayisi > 2; charSayisi--){
                for(ll runningSum = 1; runningSum <  n/2+2; runningSum++){
                    dp[2][charSayisi + 1][runningSum - 1] += dp[2][charSayisi][runningSum];
                    dp[2][charSayisi + 1][runningSum - 1] %= MOD;
                }
            }
        // STATE 1
            //Self feed
            for(ll charSayisi = n - 1; charSayisi >= 0; charSayisi--){
                for(ll runningSum = 1; runningSum <  n/2+2; runningSum++){
                    dp[1][charSayisi + 1][runningSum - 1] += dp[1][charSayisi][runningSum];
                    dp[1][charSayisi + 1][runningSum - 1] %= MOD;
                }
            }
        // STATE 0
        //State 1e gecis
            for(ll charSayisi = n - 1; charSayisi >= 0; charSayisi--){
                for(ll runningSum = 1; runningSum <  n/2+2; runningSum++){
                    dp[1][charSayisi + 1][runningSum - 1] += dp[0][charSayisi][runningSum];
                    dp[1][charSayisi + 1][runningSum - 1] %= MOD;
                }
            }
        }
        else{
            // STATE 4
            // Doesn't accept '('
        //STATE 3
            // Propogate to State 4
            for(ll charSayisi = n - 1; charSayisi >= 0; charSayisi--){
                for(ll runningSum = n/2; runningSum >= 0; runningSum--){
                    dp[3][charSayisi + 1][runningSum + 1] += dp[2][charSayisi][runningSum];
                    dp[3][charSayisi + 1][runningSum + 1] %= MOD;
                }
            }
            // Self feed
            for(ll charSayisi = n - 1; charSayisi >= 0; charSayisi--){
                for(ll runningSum = n/2; runningSum >= 0; runningSum--){
                    dp[2][charSayisi + 1][runningSum + 1] += dp[2][charSayisi][runningSum];
                    dp[2][charSayisi + 1][runningSum + 1] %= MOD;
                }
            }
        // STATE 2
        // Propogate to State 3
            for(ll charSayisi = n - 1; charSayisi >= 0; charSayisi--){
                for(ll runningSum = n/2; runningSum >= 0; runningSum--){
                    dp[2][charSayisi + 1][runningSum + 1] += dp[1][charSayisi][runningSum];
                    dp[2][charSayisi + 1][runningSum + 1] %= MOD;
                }
            }
        // STATE 1
        // self propogate
            for(ll charSayisi = n - 1; charSayisi >= 0; charSayisi--){
                for(ll runningSum = n/2; runningSum >= 0; runningSum--){
                    dp[0][charSayisi + 1][runningSum + 1] += dp[0][charSayisi][runningSum];
                    dp[0][charSayisi + 1][runningSum + 1] %= MOD;
                }
            }
            // State 1e gecis
            dp[0][1][1]++;
        }

        }
        cout << ans << "\n";
        return;
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
