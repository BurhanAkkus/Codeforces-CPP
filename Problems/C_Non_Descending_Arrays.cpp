#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
const long long MAX_N = 200000;

vector<ll> a;
vector<ll> b;


void solve(){
    ll n;
    cin >> n;
    a.assign(n+5,0);
    b.assign(n+5,0);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> b[i];
    }
    vector<vector<tuple<ll,ll,ll>>> dp(n+1,vector<tuple<ll,ll,ll>>(0));
    dp[0].push_back({0,0,1});
    for(ll i = 1; i<=n; i++){
        // duz hali
        ll duzHaliToplam = 0;
        for(ll j = 0; j < dp[i-1].size(); j++){
            auto [prefixMaxA,prefixMaxB,score] = dp[i-1][j];
            if(prefixMaxA <= a[i] && prefixMaxB <= b[i]){
                duzHaliToplam += score;
            }
        }
        dp[i].push_back({a[i],b[i],duzHaliToplam % MOD});
        
        // duz hali
        ll degismisHaliToplam = 0;
        for(ll j = 0; j < dp[i-1].size(); j++){
            auto [prefixMaxA,prefixMaxB,score] = dp[i-1][j];
            if(prefixMaxA <= b[i] && prefixMaxB <= a[i]){
                degismisHaliToplam += score;
            }
        }
        dp[i].push_back({b[i],a[i],degismisHaliToplam % MOD});
    }
    ll ans = 0;
    for(auto final:dp[n]){
        ans += get<2>(final);
    }
    cout << ans% MOD  << "\n";
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