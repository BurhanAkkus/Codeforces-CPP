#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
const ll MAX_N = 200002;
const ll block_size = 256;
ll combinationPrefixSumPrecomputeTable[MAX_N/block_size][MAX_N/block_size];

ll combination(ll n, ll k){

}

void precompute(){
    for(ll sn = 0; sn < MAX_N/block_size; sn++){
        for(ll sk = 0; sk <= sn; sk++){
            if(sk == 0){
                combinationPrefixSumPrecomputeTable[sn][sk] = 1;
            } else{
                combinationPrefixSumPrecomputeTable[sn][sk] = (combinationPrefixSumPrecomputeTable[sn-1][sk-1] + combinationPrefixSumPrecomputeTable[sn-1][sk]) % MOD;
            }
        }
    }
}

void solve(){
    ll n, X;
    cin >> n >> X;

    if(X >  n){ cout << X % MOD << "\n"; return; }
    if(X < -n){ cout << (-X % MOD + MOD) % MOD << "\n"; return; }

    computeProbabilities(n);
    computePrefixSums(n);

    ll idx  = X + MAX_N;
    ll psp  = prefixSumProb[idx];   // P(x' <= X)
    ll pe   = prefixExpected[idx];  // sum_{k=-n}^{X} k * P(k)
    ll Xmod = (X % MOD + MOD) % MOD;

    // E[|x'-X|] = (2*P(x'<=X) - 1)*X - 2*sum_{k<=-n}^{X} k*P(k)
    ll ans = ((2 * psp % MOD - 1 + MOD) % MOD * Xmod % MOD
              + MOD - 2 * pe % MOD) % MOD;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    ll T;
    cin >> T;
    while(T--) solve();
}
