#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 5000;
vector<ll> numberArray(MAX_N+5,-1);
vector<ll> numberArrayIndices(MAX_N+5,-1);

bool isInversion(ll a, ll b){
    return a > b;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<ll> diffs(n,0);
    ll totalSum = 0;
    for(ll i = 1; i < n - 1; i++){
        diffs[i] += abs(arr[i] - arr[i-1]);
        diffs[i] += abs(arr[i] - arr[i+1]);
        diffs[i] -= abs(arr[i+1] - arr[i-1]);
        totalSum += abs(arr[i] - arr[i-1]);
    }
    diffs[0] = abs(arr[0] - arr[1]);
    diffs[n-1] = abs(arr[n-1] - arr[n-2]);
    totalSum += abs(arr[n-1] - arr[n-2]);
    cout << totalSum - *max_element(diffs.begin(), diffs.end()) << "\n";
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
