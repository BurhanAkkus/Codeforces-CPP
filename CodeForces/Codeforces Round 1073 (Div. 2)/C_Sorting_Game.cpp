#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 2e5;
vector<char> numberArray(MAX_N+5,-1);
vector<ll> indexArray(MAX_N+5,-1);
vector<ll> sortedIndexArray(MAX_N+5,-1);

bool isInversion(ll a, ll b){
    return a > b;
}

void solve(){
    ll n;
    cin >> n;
    ll numberOfZeros = 0,numberOfOnes = 0;
    for(ll i = 0; i < n; i++){
        cin >> numberArray[i];
        if(numberArray[i] == '0'){
            numberOfZeros++;
        }
        else{
            numberOfOnes++;
        }
    }
    ll numberOfInversions = numberArray[0] == '1' ? 1 : 0;
    for(ll i = 1; i < n; i++){ 
        if(numberArray[i] != numberArray[i-1]){
            numberOfInversions++;
        }
    }
    if(numberOfInversions < 2){
        cout << "Bob\n";
        return;
    }
    else{
        cout<<"Alice\n";
        ll m = 0;
        for(ll i = 0; i < numberOfZeros; i++){
            if(numberArray[i] != '0'){
                m++;
            }
        }
        for(ll i = numberOfZeros; i < n; i++){
            if(numberArray[i] != '1'){m++;
            }
        }
        cout << m << "\n";

        for(ll i = 0; i < numberOfZeros; i++){
            if(numberArray[i] != '0'){
                cout << (i+1) << " ";
            }
        }
        for(ll i = numberOfZeros; i < n; i++){
            if(numberArray[i] != '1'){
                cout << (i+1) << " ";
            }
        }
        cout << "\n";
        return;
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
