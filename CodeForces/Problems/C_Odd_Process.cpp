#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

vector<ll> inputArray(static_cast<size_t>(MAX_N) + 5);
vector<ll> evens;
vector<ll> odds;
vector<ll> values(static_cast<size_t>(MAX_N) + 5);

void solve(){
    ll n;
    cin >> n;
    ll evenCount = 0;
    ll sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> inputArray[i];
        if(inputArray[i] % 2 == 0){
            evenCount++;
            evens.push_back(inputArray[i]);
        }
        else{
            odds.push_back(inputArray[i]);
        }
        sum += inputArray[i];
    }
    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());
    if(evenCount == n){
        for (ll i = 1; i <= n; i++)
        {
            cout << 0 << " ";
        }
        cout<< "\n";
        evens.clear();
        odds.clear();
    }
    else{
        values[0] = 0;
        values[1] = *max_element(odds.begin(), odds.end());
        ll evenIndex = evens.size() - 1;
        ll evenSuffixSum  = 0l;
        for(ll i = 1; i <= evenCount; i++){
            evenSuffixSum += evens[evenIndex - i + 1];
            values[1+i] = odds[odds.size() - 1] + evenSuffixSum;
        }
        for(ll i = evenCount + 2; i < n; i++){
            values[i] = values[i-2];
        }
        values[n] = odds.size() %2 == 0? 0 :evenSuffixSum + odds[odds.size() - 1];
        

        for (ll i = 1; i <= n; i++)
        {
            cout << values[i] << " ";
        }
        cout<< "\n";
        evens.clear();
        odds.clear();

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