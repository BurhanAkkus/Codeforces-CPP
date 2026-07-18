#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

// edges[i][0] => negative edges of i. edges[i][1] => positive edges of i.
array<array<set<ll>,2>,MAX_N> edges;
array<ll,MAX_N> sayilar;
array<bool,MAX_N> atandi;
ll sayi;
void solve(){
    ll n,m;
    cin >> n >> m;
    rep(i,0,n,1){
        edges[i][0].clear();
        edges[i][1].clear();
        sayilar[i] = 0;
        atandi[i] = false;
    }
    rep(i,0,m,1){
        ll o,s,r;
        cin >> o >> s >> r;
        s--;r--;
        edges[s][o==1].insert(r);
        edges[r][o==1].insert(s);
    }
    
    ll kalanNodeSayisi = n;
    sayi = 1e9;
    queue<ll> tekTaraflilar;
    rep(i,0,n,1){
        if(edges[i][0].size() == 0 && edges[i][1].size() == 0){
            sayilar[i] = sayi;
            kalanNodeSayisi--;
        }
        else{
            if(edges[i][0].size() == 0 || edges[i][1].size() == 0){
                tekTaraflilar.push(i);
            }
        }
    }
    while(!tekTaraflilar.empty()){
        ll tekTarafli = tekTaraflilar.front();
        tekTaraflilar.pop();
        if(atandi[tekTarafli]) continue;
        atandi[tekTarafli] = true;

        kalanNodeSayisi--;
        if(edges[tekTarafli][0].size() == 0){
            sayilar[tekTarafli] = sayi--;
            edges[tekTarafli][1].erase(tekTarafli);
            for(auto edge:edges[tekTarafli][1]){
                edges[edge][1].erase(tekTarafli);
                if(edges[edge][1].size() == 0){
                    tekTaraflilar.push(edge);
                }
            }
        }
        else if(edges[tekTarafli][1].size() == 0){
            sayilar[tekTarafli] = -(sayi--);
            edges[tekTarafli][0].erase(tekTarafli);
            for(auto edge:edges[tekTarafli][0]){
                edges[edge][0].erase(tekTarafli);
                if(edges[edge][0].size() == 0){
                    tekTaraflilar.push(edge);
                }
            }
        }
    }
    if(kalanNodeSayisi > 0){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    rep(i,0,n,1){
        cout << sayilar[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}
