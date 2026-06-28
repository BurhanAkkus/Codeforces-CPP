#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 100;
vector<ll> numberArray(MAX_N+5,-1);
vector<ll> indexArray(MAX_N+5,-1);
vector<ll> sortedIndexArray(MAX_N+5,-1);

bool isInversion(ll a, ll b){
    return a > b;
}

void solve(){
    ll n,c;
    cin >>n >> c;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    bool flag = true;
    for(int i = 0 ; i < n ; i++){
        if(a[i] < b[i]){
            flag = false;
            break;
        }
    }
    ll count = 0;
    if(!flag){
        count = c;
        sort(a.begin(), a.begin() + n);
        sort(b.begin(), b.begin() + n);
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]){
            cout << -1 << endl;
            return;
        }
        count += a[i] - b[i];
    }
    cout << count << endl;
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
