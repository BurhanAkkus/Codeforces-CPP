#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
const long long MAX_N = 300005;

ll repeatCounts[MAX_N];
void solve(){
    ll n,k;
    cin >> n >> k;
    rep(i,0,n+1,1){
        repeatCounts[i] = 0;
    }
    ll previous;
    cin >> previous;
    ll repeatCount = 1;
    
    ll c;
    ll harfCount = 1;
    rep(i,1,n,1){
        cin >> c;
        if(c == previous){
            repeatCount++;
        }
        else{
            repeatCounts[repeatCount]++;
            previous = c;
            harfCount++;
            repeatCount = 1;
        }
    }
    repeatCounts[repeatCount]++;
    ll ans = 0;
    ll iter = 1;
    ll kalanHarf = n;
    while(kalanHarf > 0){
        // minimize kalanHarf while kalanHarf stays constant.
        while(repeatCounts[iter] == 0){
            kalanHarf -= harfCount;
            iter++;
        }
        if(k == kalanHarf){
            ans++;
        }
        else if(k > kalanHarf && (k-kalanHarf) % harfCount == 0){
            ans++;
        }
        kalanHarf -= harfCount;
        harfCount -= repeatCounts[iter++];
    }
    cout << ans << "\n";

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
