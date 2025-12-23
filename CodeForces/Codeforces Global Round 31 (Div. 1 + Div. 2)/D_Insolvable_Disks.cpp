#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define INFINITY 1e9+1

void solve(){
    ll n ;
    cin >> n;
    vector<ll> x(n+5,0);
    vector<pair<ll,ll>> kisitlamalar(n,{0,INFINITY});
    for(ll i = 0; i < n; i++){
        cin >> x[i];
    }
    for(ll i = 0; i < n-1; i++){
        kisitlamalar[i] = {0,min(kisitlamalar[i].second, x[i+1] - x[i])};
        kisitlamalar[i+1] = {0,min(kisitlamalar[i+1].second, x[i+1] - x[i])};
    }
    ll ans = 0;
    for(ll i = 0 ; i < n-1;i++){
        pair<ll,ll> tasimaliKisitlama = kisitlamalar[i];
        ll interval = x[i+1] - x[i];
        ll j = 1;
        for(; i+j < n; j++){
            // tek sayida intervalse
            // yani ciftinci sayida sayiysa
            if(j&1){
                tasimaliKisitlama.first = max(tasimaliKisitlama.first, interval - kisitlamalar[i+j].second);
                tasimaliKisitlama.second = min(tasimaliKisitlama.second, interval);
                interval -= x[i+j+1] - x[i+j];
            }
            // ciftinci sayida intervalse
            // yani tekinci sayida sayiysa
            else{
                tasimaliKisitlama.first = max(tasimaliKisitlama.first, interval);
                tasimaliKisitlama.second = min(tasimaliKisitlama.second, interval + kisitlamalar[i+j].second);
                interval += x[i+j+1] - x[i+j];
            }
            if(tasimaliKisitlama.first >= tasimaliKisitlama.second) break;
        }
        ans += j - 1;
        i+=j - 1;
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
