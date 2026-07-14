#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 100005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


int firstPhase[MAX_N * 2];

void precomputePhaseOne(){
    firstPhase[0] = 0;
    firstPhase[1] = 1;
    firstPhase[2] = 2;
    firstPhase[3] = 3;
    rep(i,4,MAX_N *2,1){
        if(i % 2){firstPhase[i] = firstPhase[i - 1] + 1;}
        else{ firstPhase[i] = firstPhase[i>>1] + 1;}
    }
}

int a[MAX_N];
void solve(){
    ll n;
    cin >> n;
    int minTrailingZeros = INT_MAX;
    ll ans = 0;
    rep(i,0,n,1){
        cin >> a[i];
        minTrailingZeros = min(minTrailingZeros,__builtin_ctz(a[i]));
    }
    if(minTrailingZeros > 0){
        ans += minTrailingZeros;
    }
    // rep(i,0,n,1){
    //     a[i] = a[i] >> minTrailingZeros;
    //     ans += secondPhase[a[i]];
    // }
    cout << ans << "\n";
    return;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputePhaseOne();
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}