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
        indexArray[i] = numberArray[i];
    }
    sort(numberArray.begin(), numberArray.begin() + n);
    for(ll i = 0; i < n; i++){
        sortedIndexArray[numberArray[i]] = i;
    }
    bool flag = true;
    for(ll i = 1; i < n; i++){
        if(sortedIndexArray[indexArray[i-1]] %2 == sortedIndexArray[indexArray[i]] % 2){
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }



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
