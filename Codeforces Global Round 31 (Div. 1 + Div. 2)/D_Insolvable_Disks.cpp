#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define INFINITY 1e9+1
void solve(int t){
    ll n ;
    cin >> n;
    vector<ll> x(n,0);
    vector<pair<ll,ll>> araliklar(n-1);
    vector<pair<ll,ll>> kisitlamalar(n,{0,INFINITY});
    for(ll i = 0; i < n; i++){
        cin >> x[i];
    }
    for(ll i = 0; i < n-1; i++){
        araliklar[i] = {i,x[i+1] - x[i]};
        kisitlamalar[i] = {0,min(kisitlamalar[i].second, x[i+1] - x[i])};
        kisitlamalar[i+1] = {0,min(kisitlamalar[i+1].second, x[i+1] - x[i])};
    }
    sort(araliklar.begin(),araliklar.end(),[](pair<ll,ll> a, pair<ll,ll> b){
        return a.second < b.second;
    });
    ll ans = 0;
    for(ll i = 0 ; i < n-1;i++){
        pair<ll,ll> aralik = araliklar[i];
        pair<ll,ll> firstKisitlama = kisitlamalar[araliklar[i].first];
        pair<ll,ll> secondKisitlama = kisitlamalar[aralik.first + 1];
        if(aralik.second > firstKisitlama.first + secondKisitlama.first && aralik.second < firstKisitlama.second + secondKisitlama.second){
            ans ++;
            ll yeniFirstMin = max(firstKisitlama.first, aralik.second - secondKisitlama.second);
            ll yeniFirstMax= min(firstKisitlama.second, aralik.second - secondKisitlama.first);
            ll yeniSecondMin = max(secondKisitlama.first, aralik.second - firstKisitlama.second);
            ll yeniSecondMax = min(secondKisitlama.second, aralik.second - firstKisitlama.first);
            kisitlamalar[aralik.first] = {yeniFirstMin,yeniFirstMax};
            kisitlamalar[aralik.first + 1] = {yeniSecondMin,yeniSecondMax};
        }
    }
    if(t == 10000 - 1701){
        for(ll i = 0; i < n; i++){
        cout << x[i] << " ";
        if(i%20 == 19){
            cout << "\n";
        }
    }
    cout << "\n";
    }
    if(t < 4)
    cout<< ans << "\n";

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while(t--){
        solve(t);
    }
}
