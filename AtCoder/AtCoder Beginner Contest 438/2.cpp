#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    string s;
    cin >> s;
    string t;
    cin >> t;
    ll ans = Infinity;
    for(ll start = 0; start < n - m + 1; start++){
        ll currAns = 0;
        for(ll j = 0; j < m; j++){
            currAns += s[start + j] >= t[j] ? s[start + j] - t[j] : s[start +j] - t[j] + 10;
        }
        ans = min(ans,currAns);
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}