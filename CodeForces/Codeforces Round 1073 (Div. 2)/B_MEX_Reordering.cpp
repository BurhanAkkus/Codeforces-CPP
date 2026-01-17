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
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> numberArray[i];
    }
    sort(numberArray.begin(), numberArray.begin() + n);
    if(numberArray[0] != 0)
    {
        cout << "NO\n";
        return;
    }
    if(numberArray[1] != 0){
        cout << "YES\n";
        return;
    }
    ll i = 0;
    while(i < n && numberArray[i] == 0){
        i++;
    }
    if(i == n){
        cout << "NO\n";
        return;
    }
    if(numberArray[i] != 1){
        cout <<"NO\n";
        return;
    }
    cout<<"YES\n";
    return;
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
