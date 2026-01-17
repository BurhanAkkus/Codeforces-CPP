#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 2e5;
vector<char> numberArray(MAX_N+5,-1);
vector<ll> prefixAcilan(MAX_N+5,-1);

void solve(){
    ll n;
    cin >> n;
     
    for(ll i = 0; i < n; i++){
        cin >> numberArray[i];
    }
    
    prefixAcilan[0] = 1;
    for(ll i = 1; i < n; i++){
        prefixAcilan[i] = prefixAcilan[i-1] + (numberArray[i] == '(' ? 1 : 0);
    }
    for( ll i = 0; i < n; i++){
        if(numberArray[i] == '('){
            continue;
        }
        else{
            if(n/2 - prefixAcilan[i] < 2){
                cout<< "-1\n";
                return;
            }
            else{
                cout << n-2 << "\n";
                return;
            }
        }
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
