#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

vector<ll> permutation(static_cast<size_t>(MAX_N) + 5);
vector<pair<int,int>> edges(static_cast<size_t>(MAX_N) + 5);
vector<pair<ll,ll>> minMaxes(static_cast<size_t>(MAX_N) + 5);

void solve(){
    ll n;
    cin >> n;
    string s;
    s.reserve(static_cast<size_t>(n));
    cin >> s;
    ll max0 = 0;
    ll zeroStreak = 0;
    for (ll i = 0; i < n; i++)
    {
        if(s[i] == '0'){
            zeroStreak++;
            max0 = max(max0, zeroStreak);
        }
        else{
            zeroStreak = 0;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if(s[i] == '0'){
            zeroStreak++;
            max0 = max(max0, zeroStreak);
        }
        else{
            zeroStreak = 0;
        }
    }
    cout<< max0 << "\n";

    
    
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