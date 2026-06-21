#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;


bool dene(ll n, ll c,ll k, vector<pair<ll,ll>>& points){
    ll start = points[0].second;
    bool flag = true;
    for(int j = 1; j < k; j++){
        int next_index = lower_bound(points.begin(), points.begin() + n, start + c, [](const pair<ll,ll>& a, ll val){
            return a.first < val;
        }) - points.begin();
        // check if next_index is out of bounds
        if(next_index >= n){
            flag = false;
            break;
        }
        start = points[next_index].second;
    }
    if(flag){
        return true;
    }
    
    return false;
}

void solve(){
    ll n;
    cin >>n;
    ll k;
    cin >> k;
    vector<pair<ll,ll>> points(n);
    for(int i = 0; i < n; i++){
        ll x,y;
        cin >> x >> y;
        points[i] = {x,y};
    }
    sort(points.begin(), points.end(), [](const pair<ll,ll>& a, const pair<ll,ll>& b){
        return a.first < b.first ? true : (a.first == b.first ? a.second > b.second : false);
    });
    vector<pair<ll,ll>> cleaned;
    for(int i = 0; i < n; i++){
        while(!cleaned.empty() && cleaned.back().second >= points[i].second){
            cleaned.pop_back();
        }
        cleaned.push_back(points[i]);
    }
    ll lower,upper;
    lower = 0;
    upper = 1e9;
    while(lower < upper){
        // upper'i dene. middle'i dene. mumkunse lower = middle;
        // degilse upper = middle -1;
        ll middle = (lower + upper + 1) / 2;
        if(dene(cleaned.size(), middle,k, cleaned)){
            lower = middle;
        }
        else{
            upper = middle - 1;
        }
    }
    if(lower == 0){
        cout << -1 << endl;
    }
    else{
        cout << lower << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}