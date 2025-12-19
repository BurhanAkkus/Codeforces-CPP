#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define INFINITY 1e9+1
void solve(){
    ll n ;
    cin >> n;
    vector<ll> x(n,0);
    vector<pair<ll,ll>> araliklar(n-1);
    vector<pair<pair<ll,ll>,pair<bool,bool>>> kisitlamalar(n,{{1e-7,INFINITY},{false,true}});
    for(ll i = 0; i < n; i++){
        cin >> x[i];
    }
    for(ll i = 0; i < n-1; i++){
        araliklar[i] = {i,x[i+1] - x[i]};
    }
    sort(araliklar.begin(),araliklar.end(),[](pair<ll,ll> a, pair<ll,ll> b){
        return a.second < b.second;
    });
    ll ans = 0;
    for(ll i = 0 ; i < n-1;i++){
        pair<ll,ll> aralik = araliklar[i];
        pair<ll,ll> firstKisitlama = kisitlamalar[araliklar[i].first].first;
        pair<bool,bool> firstKisitlamaInclusive = kisitlamalar[araliklar[i].first].second;
        pair<ll,ll> secondKisitlama = kisitlamalar[araliklar[i].first + 1].first;
        pair<bool,bool> secondKisitlamaInclusive = kisitlamalar[araliklar[i].first + 1].second;
        if( (aralik.second > firstKisitlama.first + secondKisitlama.first && aralik.second < firstKisitlama.second + secondKisitlama.second)
        || 
            ((aralik.second == firstKisitlama.first + secondKisitlama.first && firstKisitlamaInclusive.first && secondKisitlamaInclusive.first)
            || (aralik.second == firstKisitlama.second + secondKisitlama.second && firstKisitlamaInclusive.second && secondKisitlamaInclusive.second))
    ){
            ans ++;
            ll yeniFirstMin;
            bool yeniFirstMinInclusive;
            ll yeniFirstMax;
            bool yeniFirstMaxInclusive;
            ll yeniSecondMin;
            bool yeniSecondMinInclusive;
            ll yeniSecondMax;
            bool yeniSecondMaxInclusive;

            if(firstKisitlama.first >aralik.second - secondKisitlama.second ){
                yeniFirstMin = firstKisitlama.first;
                yeniFirstMinInclusive = firstKisitlamaInclusive.first;
            }
            else if(firstKisitlama.first == aralik.second - secondKisitlama.second ){
                yeniFirstMin = firstKisitlama.first;
                yeniFirstMinInclusive = firstKisitlamaInclusive.first && secondKisitlamaInclusive.second;
            }else{
                yeniFirstMin = aralik.second - secondKisitlama.second;
                yeniFirstMinInclusive = secondKisitlamaInclusive.second;
            }

            if(firstKisitlama.second < aralik.second - secondKisitlama.first ){
                yeniFirstMax = firstKisitlama.second;
                yeniFirstMinInclusive = firstKisitlamaInclusive.second;
            }
            else if(firstKisitlama.second == aralik.second - secondKisitlama.first ){
                yeniFirstMax = firstKisitlama.second;
                yeniFirstMinInclusive = firstKisitlamaInclusive.second && secondKisitlamaInclusive.first;
            }else{
                yeniFirstMax = aralik.second - secondKisitlama.first;
                yeniFirstMinInclusive = secondKisitlamaInclusive.first;
            }

            if(secondKisitlama.first > aralik.second - firstKisitlama.second ){
                yeniSecondMin = secondKisitlama.first;
                yeniSecondMinInclusive = secondKisitlamaInclusive.first;
            }
            else if(secondKisitlama.first == aralik.second - firstKisitlama.second ){
                yeniSecondMin = secondKisitlama.first;
                yeniSecondMinInclusive = firstKisitlamaInclusive.second && secondKisitlamaInclusive.first;
            }else{
                yeniSecondMin = aralik.second - firstKisitlama.second;
                yeniSecondMinInclusive = firstKisitlamaInclusive.second;
            }
        
            if(secondKisitlama.second < aralik.second - firstKisitlama.first ){
                yeniSecondMax = secondKisitlama.second;
                yeniSecondMaxInclusive = secondKisitlamaInclusive.second;
            }
            else if(secondKisitlama.second == aralik.second - firstKisitlama.first ){
                yeniSecondMax = secondKisitlama.second;
                yeniSecondMaxInclusive = firstKisitlamaInclusive.first && secondKisitlamaInclusive.second;
            }else{
                yeniSecondMax = aralik.second - firstKisitlama.first;
                yeniSecondMaxInclusive = firstKisitlamaInclusive.first;
            }
            
            kisitlamalar[aralik.first] = {{yeniFirstMin,yeniFirstMax},{yeniFirstMinInclusive,yeniFirstMinInclusive}};
            kisitlamalar[aralik.first + 1] = {{yeniSecondMin,yeniSecondMax},{yeniSecondMinInclusive,yeniSecondMinInclusive}};
        }
    }
    cout<< ans << "\n";

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
