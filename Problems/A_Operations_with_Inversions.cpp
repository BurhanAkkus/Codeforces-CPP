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
    ll prefixMax = -Infinity;
    ll ans = 0;
    for (ll  i = 0; i < n; i++)
    {   ll newComer;
        cin >> newComer;
        if(newComer >= prefixMax){
            prefixMax = newComer;
            ans++;
        }
    }
    cout << n-ans << "\n";
    
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