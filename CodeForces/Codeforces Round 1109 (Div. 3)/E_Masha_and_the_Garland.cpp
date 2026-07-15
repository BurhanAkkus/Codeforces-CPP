#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll neighbourPrefixSum[MAX_N];
void solve(){
    ll n,q;
    cin >> n >> q;
    neighbourPrefixSum[0] = 0;
    string s;
    cin >> s;
    rep(i,1,n,1){
        neighbourPrefixSum[i] = neighbourPrefixSum[i - 1] + (s[i] == s[i-1]);
    } 
    rep(i,0,q,1){
        ll l,r,k;
        cin >> l >> r >> k;
        l--;r--;
        if(k >= (neighbourPrefixSum[r] - neighbourPrefixSum[l] +1)/2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

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