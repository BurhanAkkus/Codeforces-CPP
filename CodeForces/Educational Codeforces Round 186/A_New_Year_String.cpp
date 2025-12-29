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
    string s;
    cin >> s;
    ll ans = Infinity;
    ll localAns = 0;
    for(ll i = 3; i <= n-1; i++){
        localAns = 0;
        if(s[i-3] != '2'){
            localAns++;
        }
        if(s[i-2] != '0'){
            localAns++;
        }
        if(s[i-1] != '2'){
            localAns++;
        }
        if(s[i] != '6'){
            localAns++;
        }
        ans =  min(ans,localAns);
    }
    // ans = 2026'ya olan mesafe.
    ll ans2 = 0;
    for(ll i = 3; i <= n-1; i++){
        localAns = 0;
        if(s[i-3] == '2' &&s[i-2] == '0' && s[i-1] == '2' && s[i] == '5'){
            ans2 = 1;
        }
    }
    cout << min(ans,ans2) << "\n";
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
