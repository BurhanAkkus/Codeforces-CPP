#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX

void solve(){
    ll a,b;
    cin >> a >> b;
    if(3 * a > 2*b){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

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