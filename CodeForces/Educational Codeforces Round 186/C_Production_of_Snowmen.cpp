#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 5000;
vector<ll> a(MAX_N+4);
vector<ll> b(MAX_N+4);
vector<ll> c(MAX_N+4);

void solve(){
    ll n;
    cin >> n;
    for(ll i = 0 ; i < n; i++){
        cin >> a[i];
    }
    
    for(ll i = 0 ; i < n; i++){
        cin >> b[i];
    }
    
    for(ll i = 0 ; i < n; i++){
        cin >> c[i];
    }
    ll iToJ = 0;
    for(ll j = 0; j < n; j++){
        bool flag = true;
        for(ll step = 0; step < n; step++){
            if(a[step] >= b[(j+step) % n])
            {
                flag = false;
                break;
            }
        }
        if(flag){
            iToJ++;
        }
    }

    ll jToK = 0;
    for(ll k = 0; k < n; k++){
        bool flag = true;
        for(ll step = 0; step < n; step++){
            if(b[step] >= c[(k+step) % n])
            {
                flag = false;
                break;
            }
        }
        if(flag){
            jToK++;
        }
    }
    cout << n* iToJ * jToK << "\n";

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
