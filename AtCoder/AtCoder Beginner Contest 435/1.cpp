#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    vector<ll> numbers(static_cast<size_t>(n) + 5);
    vector<ll> prefixSum(static_cast<size_t>(n) + 5);
    prefixSum[0] = 0;   
    for(ll i = 1; i <= n; i++){
        cin >> numbers[i];
        prefixSum[i] = prefixSum[i-1] + numbers[i];
    }
    ll ans = 0;
    for(ll l = 1; l <= n; l++){
        for(ll r = l; r <= n; r++){
            bool flag = false;
            for(ll i = l; i <= r; i++){
                if((prefixSum[r] - prefixSum[l-1]) % numbers[i] == 0){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans++;
            }
        }
    }
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}