#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 300005;
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))



void solve(){
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    // odd length
    rep(middle,0,n,1){
        bool faultUsed = false;
        rep(radius,0,min(middle + 1,n-middle),1){
            if(s[middle + radius] == s[middle-radius]){
                ans++;
            }
            else if(!faultUsed){
                faultUsed = true;
                ans++;
            }
            else{
                break;
            }
        }    
    }
    // even length
    rep(middle,0,n,1){
        bool faultUsed = false;
        rep(radius,0,min(middle+1,n - middle - 1),1){
            if(s[middle-radius] == s[middle + 1 + radius]){
                ans++;
            }
            else if(!faultUsed){
                faultUsed = true;
                ans++;
            }
            else{
                break;
            }
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}