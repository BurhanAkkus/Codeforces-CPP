#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 300000;

vector<ll> scoreKatkisi(MAX_N+4);

void solve(){
    ll n;
    cin >> n;
    ll agirlik;
    ll guc;
    ll sumPower = 0;
    for(ll i = 0; i < n; i++){
        cin >> agirlik >> guc;
        scoreKatkisi[i] = guc + agirlik;
        sumPower += guc;
    }
    sort(scoreKatkisi.begin(), scoreKatkisi.begin()+n);
    ll i = 0;
    while(i < n && sumPower >= 0){
        sumPower -= scoreKatkisi[i];
        i++;
    }
    if(sumPower < 0){
        i--;
    }
    cout << i << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)   solve();
}