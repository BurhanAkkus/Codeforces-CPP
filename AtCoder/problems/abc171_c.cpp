#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


void solve(){
    ll n;
    cin >>n;
    ll digitSayisi = 0;
    ll sayi = 0;
    ll eklenecek = 26;
    while(sayi < n){
        sayi += eklenecek;
        eklenecek *= 26;
        digitSayisi++;
    }
    ll kalan = n;
    ll cikarilacak = 26;
    rep(i,0,digitSayisi - 1,1){
        kalan -= cikarilacak;
        cikarilacak *= 26;
    }
    kalan--;
    string s = "";
    while(digitSayisi > 0){
        s = char('a' + (kalan % 26)) + s;
        kalan /= 26;
        digitSayisi--;
    }
    cout << s;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
