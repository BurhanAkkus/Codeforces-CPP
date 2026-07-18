#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 1000005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll a[MAX_N],b[MAX_N],sorted[MAX_N];
ll n,q;

// can the array be sorted using blocks of size 2^t ?
bool solvesForT(ll t){
    rep(i,0,n,1){
        b[i] = a[i];
    }
    ll blockSize = 1LL << t;
    rep(i,0,n,blockSize){
        sort(b+i,b+min(i+blockSize,n)); // last block is ragged
    }

    rep(i,0,n,1){
        if(b[i] != sorted[i])
        return false;
    }
    return true;
}

ll lower_bound_custom(){
    // answer lies [l,r), r is excluded. searching the exponent.
    ll l = 0;
    ll r = MAX_K;
    while(l < r){
        ll mid = l + (r - l) /2; // rounds down.
        if(solvesForT(mid)) {r=mid;} // shrinks the interval [l,r)
        else{
            l= mid+1; // shrinks the interval.
        }
    }
    return l;
}


void solve(){
    
    cin >> n >> q;
    rep(i,0,n,1){
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted,sorted+n);
    ll t = lower_bound_custom();
    cout << (t == 0 ? 0LL : (1LL << (t-1))) << "\n";
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}