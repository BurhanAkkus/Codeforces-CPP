#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity 1e15

const size_t D = 360 + 1;
const size_t TOT = D * D;                      
vector<ll> dp(TOT, 0);                          

// i= kullanilan Kart, k = maxValue
auto IDX = [](size_t i, size_t k) -> size_t {
    return (i * D + k);
};


void solve(){
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    vector<long long> cards(n);
    for(long long i = 0; i < n;i++){
        cin >> cards[i];
    }
    vector<int> pos(k + 1, 0);
    int jptr = 0;
    for (ll x = 1; x <= k; x++) {
        while (jptr < n && cards[jptr] < x) ++jptr;
        if (jptr < n) pos[x] = jptr;
        else pos[x] = -1;
    }
    fill(dp.begin(), dp.end(), (ll)(-Infinity));
    dp[IDX(0, 0)] = 0;
    ll ans = 0;
    
    for(ll maxValue = 1; maxValue <= k && pos[maxValue] != -1; maxValue++){
        for(ll usedCards = 0; usedCards <= k- maxValue; usedCards++){
            for(ll previousMax = 0; previousMax <= usedCards && previousMax < maxValue; previousMax++){
                dp[IDX(usedCards + maxValue, maxValue)] = max(
                    dp[IDX(usedCards + maxValue, maxValue)],
                    dp[IDX(usedCards, previousMax)] + (n - pos[maxValue]) * (maxValue  - previousMax)
                );
            }
        }
    }
    for(ll usedCards = 0; usedCards <= k; usedCards++){
        for(ll maxV = 0; maxV <= usedCards; maxV++){
            ans = max(ans, dp[IDX(usedCards, maxV)]);
        }
    } 
    cout << ans << "\n";
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