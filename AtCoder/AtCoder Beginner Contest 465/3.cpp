#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> o;
    
    vector<ll> sonuc(n);
    for(int i = 0; i < n; i++){
        if(s[i] == 'o') o.push_back(i); 
    }
    for(int i = 0; i < n; i++){
        sonuc[i] = i + 1;
    }
    if(o.size() == 0){
        for(int i = 0; i < n; i++){
            cout << sonuc[i] << " ";
        }
        cout << "\n";
        return;
    }
    ll rightO = o.size() - 1;
    ll rightWrite= o[rightO];
    ll leftWrite = 0;
    
    while(rightO > 0){
        for(int i = o[rightO]; i > o[rightO - 1]; i--){
            sonuc[leftWrite++] = i + 1;
        }
        rightO--;
        if(rightO == 0) break;
        for(int i = o[rightO]; i > o[rightO - 1]; i--){
            sonuc[rightWrite--] = i + 1;
        }
        rightO--;
    }
    if(o.size() % 2 == 1)
        for(int i = o[rightO]; i >= 0; i--){
            sonuc[leftWrite++] = i + 1;
        }
    else{
        for(int i = 0; i <= o[0]; i++){
            sonuc[leftWrite++] = i + 1;
        }
    }
    for(int i = 0; i < n; i++){
        cout << sonuc[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}