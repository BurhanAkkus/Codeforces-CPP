#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define MAX_K 25
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>
using namespace std;

array<vector<ll>,3> bolunenler;
array<ll,MAX_N> a;
vector<ll> bolunmeyenler;
void solve(){
    ll n;
    cin >>n;
    rep(i,0,3,1){
        bolunenler[i].clear();
    }
    bolunmeyenler.clear();
    rep(i,0,n,1){
        cin >> a[i];
        if(a[i] % 6 == 0){
            bolunenler[0].push_back(a[i]);
        }
        else if(a[i] % 2 == 0){
            bolunenler[1].push_back(a[i]);
        }
        else if(a[i] % 3 == 0){
            bolunenler[2].push_back(a[i]);
        }
        else{
            bolunmeyenler.push_back(a[i]);
        }
    }
    for(auto two:bolunenler[1]){
        cout << two << " ";
    }
    
    
    for(auto bolunmeyen:bolunmeyenler){
        cout << bolunmeyen << " ";
    }

    for(auto three:bolunenler[2]){
        cout << three << " ";
    }
    
    for(auto six:bolunenler[0]){
        cout << six << " ";
    }
    cout << "\n";
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
