#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 1000100
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        array<vector<ll>,26> tNinHarfleri;
        rep(harf,0,26,1){
            tNinHarfleri[harf] = vector<ll>();
        }
        rep(tIndex,0,(int)t.size(),1){
            tNinHarfleri[t[tIndex] - 'a'].push_back(tIndex);
        }
        vector<array<ll,2>> dp(s.size()+1,{Infinity,Infinity});
        dp[0] = {-1,-1};
        rep(sIndex,0,(int)s.size(),1){
            ll harf = s[sIndex] - 'a';
            // hilesiz
            // to hilesiz
            auto it = upper_bound(tNinHarfleri[harf].begin(), tNinHarfleri[harf].end(), dp[sIndex][0]);
            if(it != tNinHarfleri[harf].end())
                dp[sIndex+1][0] = min(dp[sIndex+1][0], *it);  
            // to hileli
            if(dp[sIndex][0] < (int)t.size() - 1){
                dp[sIndex+1][1] = min(dp[sIndex+1][1],dp[sIndex][0] + 1);
            }
            // hileli
            it = upper_bound(tNinHarfleri[harf].begin(), tNinHarfleri[harf].end(), dp[sIndex][1]);
            if(it != tNinHarfleri[harf].end())
                dp[sIndex+1][1] = min(dp[sIndex+1][1], *it);  
        }
        if(dp[s.size()][0] != Infinity || dp[s.size()][1] != Infinity) return true;
        return false;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s,t;
    cin >> s >> t;
    cout << (solution.canMakeSubsequence(s,t) ? "true" : "false") << "\n";
}