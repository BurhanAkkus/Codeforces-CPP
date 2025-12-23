#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
const long long MAX_N = 300000;

vector<priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>> order(MAX_N+5);

void traverse(ll currentTop){
    while(!order[currentTop].empty()){
        auto [ekledigimSayi,idx]=order[currentTop].top();
        order[currentTop].pop();
        stack<ll> buSeviyedeBirbirininAynisiOlanlar;
        cout << idx << " ";
        while(!order[currentTop].empty() && order[currentTop].top().first==ekledigimSayi){
            buSeviyedeBirbirininAynisiOlanlar.push(order[currentTop].top().second);
            cout << order[currentTop].top().second << " ";
            order[currentTop].pop();
        }
        while(!buSeviyedeBirbirininAynisiOlanlar.empty()){
            while(order[buSeviyedeBirbirininAynisiOlanlar.top()].size() > 0){
                order[idx].push(order[buSeviyedeBirbirininAynisiOlanlar.top()].top());
                order[buSeviyedeBirbirininAynisiOlanlar.top()].pop();
            }
            buSeviyedeBirbirininAynisiOlanlar.pop();
        }
        traverse(idx);
    }
}
void solve(){
    ll n ;
    cin >> n;
    ll x,y;
    
    for(ll i = 0; i < n; i++){
        cin >> x >> y;
        order[x].push({y,i+1});
    }
    traverse(0);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    while(t--)   solve();
}