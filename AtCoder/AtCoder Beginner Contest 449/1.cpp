#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX
#define _USE_MATH_DEFINES

array<ll,105> a;
void solve(){
    ll n;
    cin >> n;
    long double ans = std::numbers::pi_v<long double> * n * n / 4;
    std::cout << std::format("{:.8f}\n", ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin >> t;
    while(t--){   
        solve();
    }
}