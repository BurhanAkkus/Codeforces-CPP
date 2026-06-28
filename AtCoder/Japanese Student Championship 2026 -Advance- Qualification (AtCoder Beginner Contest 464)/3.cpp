#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 300000;

const long long MAX_M = 300000;




void solve(){
    ll n,m;
    cin >> n >> m;
    int ans = 0;
    vector<array<ll, 3>> birds(n + 2);
    vector<ll> colorCounts(n + 2, 0);
    for(ll i = 0; i < n; i++){
        ll a,d,b;
        cin >> a >> d >> b;
        birds[i][0] = d ;
        birds[i][1] = a;
        birds[i][2] = b;
        colorCounts[a]++;
        if(colorCounts[a] == 1){
            ans++;
        }
    }
    sort(birds.begin(), birds.begin() + n);
    int birdIterator = 0;
    for(int day = 1; day <= m; day ++){
        while(birds[birdIterator][0] == day){
            colorCounts[birds[birdIterator][1]]--;
            if(colorCounts[birds[birdIterator][1]] == 0){
                ans--;
            }
            colorCounts[birds[birdIterator][2]]++;
            if(colorCounts[birds[birdIterator][2]] == 1){
                ans++;
            }
            birdIterator++;
        }
        cout << ans<< endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}