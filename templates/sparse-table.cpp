#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define MAX_K 25
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>
using namespace std;

array<array<ll,MAX_N>,MAX_K> sparseTable;

ll f(ll first, ll second){
    return min(first,second);
}

void calculateSparse(ll n){
    rep(i,1,MAX_K,1){
        rep(j,1,n - (1 << i) + 2,1){
            sparseTable[i][j] = f(sparseTable[i-1][j],sparseTable[i-1][j + (1 << (i-1))]);
        }
    }
}

ll log2Floor(ll n){
    return n ? __builtin_clzll(1) - __builtin_clzll(n) : -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    rep(i,1,n + 1,1){
        cin >> sparseTable[0][i];
    }
    calculateSparse(n);

    rep(i,0,m,1){
        ll l,r;
        cin >> l >> r;
        ll k = log2Floor(r-l+1);
        cout << f(sparseTable[k][l],sparseTable[k][r - (1 << k) + 1]) << "\n";
    }
}
