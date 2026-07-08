#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define repRev(i,start,end,decrement) for(ll i=(start);i>(end);i-=(decrement))
const long long MAX_N = 5005;


ll aBasamaklar[MAX_N],bBasamaklar[MAX_N];
ll aPrefixDigitSums[MAX_N],bPrefixDigitSums[MAX_N];
ll aSuffixDigitSums[MAX_N],bSuffixDigitSums[MAX_N];
array<vector<ll>,10> aDigitleriGordugumYerler;
array<vector<ll>,10> bDigitleriGordugumYerler;
ll dp[MAX_N][MAX_N];
void solve(){
    string a,b;
    cin >> a;
    cin >> b;
    rep(digit,0,10,1){
        aDigitleriGordugumYerler[digit].clear();
        bDigitleriGordugumYerler[digit].clear();
    }
    rep(i,0,a.size(),1){
        aBasamaklar[i] = a[i] - '0';}
    ll aSize = a.size();
    ll bSize = b.size();
    repRev(i,aSize-1,-1,1){
        if(aBasamaklar[i] == 0){
            aSize = i;
        }
        else{
            break;
        }
    }
    repRev(i,bSize-1,-1,1){
        if(bBasamaklar[i] == 0){
            bSize = i;
        }
        else{
            break;
        }
    }
    aPrefixDigitSums[0] = 0;
    rep(i,1,aSize + 1,1){
        aPrefixDigitSums[i] = aPrefixDigitSums[i-1] + aBasamaklar[i - 1];
        aPrefixDigitSums[i] %= 10;
        aDigitleriGordugumYerler[aPrefixDigitSums[i]].push_back(i);
    } 
    rep(i,0,bSize,1){
        bBasamaklar[i] = b[i] - '0';};
    bPrefixDigitSums[0] = 0; 
    rep(i,1,bSize + 1,1){
        bPrefixDigitSums[i] = bPrefixDigitSums[i-1] + bBasamaklar[i - 1];
        bPrefixDigitSums[i] %= 10;
        bDigitleriGordugumYerler[bPrefixDigitSums[i]].push_back(i);
    } 
    rep(i,0,aSize + 1,1){
        rep(j,0,bSize + 1,1){
            dp[i][j] = 0;
        }
    }
    queue<pair<ll,ll>> operationQ;
    operationQ.push({0,0});
    while(!operationQ.empty()){
        auto& [l,r] = operationQ.front();
        operationQ.pop();
        rep(digit,0,10,1){
            // look for the next places where aPrefixSum[i] = digit and bPrefixSum[j] = digit
            ll i = -1;
            auto it = upper_bound(aDigitleriGordugumYerler[digit].begin(),
                      aDigitleriGordugumYerler[digit].end(), l);
            if (it != aDigitleriGordugumYerler[digit].end()) {
                i = *it;   
            }
            ll j = -1;
            it = upper_bound(bDigitleriGordugumYerler[digit].begin(),
                      bDigitleriGordugumYerler[digit].end(), r);
            if (it != bDigitleriGordugumYerler[digit].end()) {
                j = *it;   
            }
            if(i != -1 && j != -1){
                dp[i][j] = max(dp[i][j],dp[l][r] + 1);
                operationQ.push({i,j});
            }
        }
    }
    cout << (dp[a.size()][b.size()] > 0?dp[a.size()][b.size()]: -1) << "\n";

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
