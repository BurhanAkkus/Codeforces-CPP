#include <bits/stdc++.h>
using namespace std;

#define ll long long 


void solve(){
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    if(k % 2 == 1){
        for(ll i = 0; i < k; i++){
            cout << n<< " ";
        }
        cout << "\n";
        return;
    }
    else{
        ll bitCount = 0;
        ll nCopy = n;
        while(nCopy > 0){
            bitCount++;
            nCopy = nCopy >> 1;
        }
        bitCount--;
        vector<ll> ans(k,0);
        ll sayac = k-1;
        
        for(ll i = bitCount; i >= 0; i--){
            ll bit = (n >> i) & 1;
            if(bit == 1){
                for(ll j = 0; j < k; j++){
                    if(j != sayac){
                        ans[j] += (1LL << i);
                    }
                }
                if(sayac < 0){
                    ans[k-1] -= (1LL << i);
                }
                sayac--;
            }
            else{
                for(ll j =sayac+1 > 0? sayac+1:0; j < k; j++ ){
                    ans[j] += (1LL << i);
                }
                if(sayac >=0){
                ans[k-1] -= (~sayac&1) * (1LL << i);
                }
            }
        }
        ll XOR = 0;
        for(ll i = 0; i < k; i++){
                    cout << ans[i]<< " ";
                    XOR ^= ans[i];
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
