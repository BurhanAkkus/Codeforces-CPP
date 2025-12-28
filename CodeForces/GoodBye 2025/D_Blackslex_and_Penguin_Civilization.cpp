#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 5000;
vector<ll> numberArray(MAX_N+5,-1);
vector<ll> numberArrayIndices(MAX_N+5,-1);

bool isInversion(ll a, ll b){
    return a > b;
}

void solve(){
    ll n;
    cin >> n;
    ll kaydirmaSayisi = n;
    while(kaydirmaSayisi >= 0){
        for(ll i = 0; i < pow(2,n-kaydirmaSayisi); i+=2){
            cout << (i<<kaydirmaSayisi) + pow(2,kaydirmaSayisi) - 1 << " ";
        }
        kaydirmaSayisi--;
    }
    cout << "\n";
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
