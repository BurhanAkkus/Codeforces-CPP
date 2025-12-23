#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
const long long MAX_N = 300000;

vector<ll> a(MAX_N+4);
vector<ll> b(MAX_N+4);
vector<ll> bPrefixSum(MAX_N+4,0);

ll binarySearch(ll val, ll n){
    ll left = 0;
    ll right = n-1;
    ll ans = -1;
    while(left <= right){
        ll mid = left + (right - left)/2;
        if(b[mid] <= val){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return ans;
}

void solve(){
    ll n ;
    cin >> n;
    ll m;
    cin >> m;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.begin()+m);
    bPrefixSum[0] = b[0];
    for(ll i = 1; i < m; i++){
        bPrefixSum[i] = bPrefixSum[i-1] + b[i];
        bPrefixSum[i] %= MOD;
    }
    ll totalScore = 0;
    for(ll i = 0; i < n; i++){
        ll idx = binarySearch(a[i], m);
        totalScore += ((idx + 1) * a[i])- (idx >= 0? bPrefixSum[idx] : 0);
        totalScore += bPrefixSum[m - 1] - (idx >= 0? bPrefixSum[idx] : 0) - ((m - idx - 1) * a[i]);
        totalScore = (totalScore % MOD + MOD) % MOD;
    }
    cout << totalScore << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    while(t--)   solve();
}