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
    for(ll i = 0 ; i < n; i++){
        cin >> numberArray[i];
        numberArrayIndices[numberArray[i]] = i;
    }

    for(ll cur = 1; cur <= n; cur++){
        ll currentIndex = numberArrayIndices[cur];
        ll inverted = 2 * n - numberArray[currentIndex];
        ll invertedInversionCount = 0;
        ll current = numberArray[currentIndex];
        ll inversionCount = 0;
        for(ll i = 0; i < n; i++){
            if(i == currentIndex){
                continue;
            }
            if(i < currentIndex){
                if(numberArray[i] > current){
                    inversionCount++;
                }
                if(numberArray[i] > inverted){
                    invertedInversionCount++;
                }
            }
            else{
                if(numberArray[i] < current){
                    inversionCount++;
                }
                if(numberArray[i] < inverted){
                    invertedInversionCount++;
                }
            }
        }
        if(invertedInversionCount < inversionCount){
            numberArray[currentIndex] = inverted;
        }
    }
    ll inversionCount = 0;
    for(ll cur = 0; cur < n; cur++){
        for(ll i = cur + 1; i < n; i++){
            if(numberArray[i] < numberArray[cur]){
                inversionCount++;
            }
        }
    }
    cout << inversionCount << "\n";



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
