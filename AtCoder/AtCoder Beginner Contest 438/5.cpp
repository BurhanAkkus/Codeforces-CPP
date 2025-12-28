#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

vector<vector<ll>> paths(MAX_N+5,vector<ll>(50));
vector<vector<ll>> mesafeler(MAX_N+5,vector<ll>(50));

ll getAns(ll t, ll b){
    if(t == 0){
        return 0;
    }
    int i = 0;
    ll temp = t;
    while(temp > 0){
        temp =  temp >> 1;
        i++;
    }
    return mesafeler[b][i-1] + getAns(t - (1<< (i-1)),paths[b][i-1]);
}

void solve(){
    ll n;
    cin >>n;
    ll q;
    cin >> q;
    for(ll i = 1; i <= n; i++){
        cin >> paths[i][0];
         mesafeler[i][0] = i;
    }
    for(ll i = 1; i < 50; i++){
        for(ll node = 1; node <= n; node++){
            paths[node][i] = paths[paths[node][i-1]][i-1];
        }
    }
    for(ll i = 1; i < 50; i++)
    {
        for(ll node = 1; node <= n; node++){
            mesafeler[node][i] = mesafeler[node][i-1] + mesafeler[paths[node][i-1]][i-1];
        }
    }

    ll t,b;
    for(ll i = 0; i < q; i++){
        cin >> t >> b;
        cout << getAns(t,b) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}