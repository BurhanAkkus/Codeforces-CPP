#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 5000;
vector<ll> numberArray(MAX_N+5,-1);
vector<ll> numberArrayIndices(MAX_N+5,-1);


void solve(){
    ll n;
    cin >> n;
    vector<string> strings(n,"");
    for(ll i = 0; i < n; i++){
        cin >> strings[i];
    }
    string s = strings[0];
    for(ll i= 1; i < n; i++){
        string first ="";
        first += strings[i];
        first += s;
        string second ="";
        second += s;
        second += strings[i];
        if(first<second){
            s = first;
        }
        else{
            s = second;
        }
    }
    cout<< s<< "\n";
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
