#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define MAX_N2 20002
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>
using namespace std;

ll arr[MAX_N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,q;
    cin >> n >> q;
    rep(i,0,q,1){
        ll l,r,x;
        cin >> l >> r >> x;
        arr[l] += x;
        arr[r+1] -= x; 
    }
    ll c = 0;
    rep(i,0,n,1){
        c+=arr[i];
        cout << c << " ";
    }
}
