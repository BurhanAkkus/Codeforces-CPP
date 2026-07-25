#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX


array<ll,11> p,q;
array<bool,11> pKullandi,qKullandi;

ll fact(int n){
    ll product = 1;
    rep(i,1,n + 1,1){
        product*= i;
    }
    return product;
}

void solve(){
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> p[i];
    }
    bool equalFlag = true;
    bool greater = true;
    rep(i,0,n,1){
        cin >> q[i];
        if(equalFlag && q[i] < p[i]){
            greater = false;
            equalFlag = false;
        }
        if(equalFlag && q[i] > p[i]){
            greater = true;
            equalFlag = false;
        }
    }
    ll pNinSirasi = 0;
    ll qNunSirasi = 0;
    rep(digit,0,n,1){
        ll kucukDigitCounter = 0;
        rep(kucukDigit,1,p[digit],1){
            if(!pKullandi[kucukDigit]){
                kucukDigitCounter++;
            }
        }
        pKullandi[p[digit]] = true;
        pNinSirasi += kucukDigitCounter * fact(n - digit - 1);
    }
    
    rep(digit,0,n,1){
        ll kucukDigitCounter = 0;
        rep(kucukDigit,1,q[digit],1){
            if(!qKullandi[kucukDigit]){
                kucukDigitCounter++;
            }
        }
        qKullandi[q[digit]] = true;
        qNunSirasi += kucukDigitCounter * fact(n - digit - 1);
    }
    if(qNunSirasi > pNinSirasi){
        cout << (qNunSirasi - pNinSirasi - 1);
        return;
    }
    cout << 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin >> t;
    while(t--){   
        solve();
    }
}