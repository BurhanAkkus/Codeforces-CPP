#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 2e5;

vector<ll> nums(MAX_N + 5);
vector<ll> prefixSum(MAX_N + 5);
vector<ll> suffixSum(MAX_N + 5);

void solve(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> nums[i];
        prefixSum[i] = i > 0 ?(prefixSum[i-1] + abs(nums[i])) : nums[0];
    }
    suffixSum[n] = 0;
    for(ll i = n-1; i >=0; i--){
        suffixSum[i] = suffixSum[i+1] + nums[i];
    }
    ll ans = -Infinity;
    for(ll i = 1; i < n; i++){
        ans = max(ans,prefixSum[i-1] - suffixSum[i+1]);
    }
    ans= max(ans,-suffixSum[1]);
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
