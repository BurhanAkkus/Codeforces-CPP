#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 1000005
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

struct Streak{
    bool isWinStreak;
    size_t length;
    pair<size_t,size_t> maxWinLose;
    size_t maxWinLosePointer;
    public:
    Streak(bool _isWinStreak,size_t _length): isWinStreak(_isWinStreak),length(_length){
        if(isWinStreak){
            maxWinLose = {length,0};
        }
        maxWinLosePointer = 0;
    };

};

bool compareWinRates(pair<ll,ll> winRate1,pair<ll,ll> winRate2){
    return winRate1.first * winRate2.second >= winRate2.first * winRate1.second;
}

pair<ll,ll> uniteWinRates(pair<ll,ll> winRate1, pair<ll,ll> winRate2){
    return {winRate1.first + winRate2.first, winRate1.second + winRate2.second};
}

// starting Index, length
vector<Streak> loseStreaks,winStreaks;
vector<ll> winStreakPrefixSums,loseStreakPrefixSums;
void solve(){
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll prev = 0,prev2 = 0;
    ll runningCount = 1;
    rep(i,1,n,1){
        if(s[i] == s[i-1]){
            runningCount++;
        }
        else{
            if(winStreaks.size() == 0 && s[i-1] == 'x'){runningCount = 1; continue;}
            if(s[i - 1] == 'o'){
                winStreaks.push_back(Streak(s[i - 1] == 'o', runningCount));
                winStreakPrefixSums.push_back(prev + runningCount); prev = prev + runningCount;}
            else{
                loseStreaks.push_back(Streak(s[i - 1] == 'o', runningCount));
                loseStreakPrefixSums.push_back(prev2 + runningCount); prev2 = prev2 + runningCount;
            }
            runningCount = 1;
        }
    }
    if(s[n-1] == 'o'){winStreaks.push_back(Streak(true, runningCount)); winStreakPrefixSums.push_back(prev + runningCount);}
    // Streaks have WinStreak at the start and at the end.
    rep(i,0,loseStreaks.size(),1){
        auto& loseStreak = loseStreaks[i];
        loseStreak.maxWinLose = {winStreaks[i+1].length,loseStreak.length};
        loseStreak.maxWinLosePointer = i;
    }
    rep(i,1,loseStreaks.size(),1){
        size_t index = loseStreaks.size()-1-i;
        auto& cur = loseStreaks[index];
        while(cur.maxWinLosePointer + 1 < loseStreaks.size()){
            auto& nxt = loseStreaks[cur.maxWinLosePointer + 1];
            if(compareWinRates(cur.maxWinLose, nxt.maxWinLose)) break; // cur >= nxt: done
            cur.maxWinLose        = uniteWinRates(cur.maxWinLose, nxt.maxWinLose);
            cur.maxWinLosePointer = nxt.maxWinLosePointer;
        }
    }
    prev = 0;
    double ans = 0;
    rep(i,0,winStreaks.size(),1){
        ll sufficientWinStreakIndex = lower_bound(winStreakPrefixSums.begin(),winStreakPrefixSums.end(),prev + k) - winStreakPrefixSums.begin();
        if(sufficientWinStreakIndex == winStreaks.size()){break;}
        pair<ll,ll> myWinLoseRate = {winStreakPrefixSums[sufficientWinStreakIndex] - prev,(sufficientWinStreakIndex > 0 ? loseStreakPrefixSums[sufficientWinStreakIndex -1] : 0) - (i > 0 ? loseStreakPrefixSums[i - 1] : 0)};
        ll dahilEttigimSonLostStreak = sufficientWinStreakIndex;
        while(dahilEttigimSonLostStreak < loseStreaks.size() && compareWinRates(loseStreaks[dahilEttigimSonLostStreak].maxWinLose,myWinLoseRate)){
            myWinLoseRate = uniteWinRates(myWinLoseRate,loseStreaks[dahilEttigimSonLostStreak].maxWinLose);
            dahilEttigimSonLostStreak = loseStreaks[dahilEttigimSonLostStreak].maxWinLosePointer + 1;
        }
        ans = max(ans,1.0 * myWinLoseRate.first / (myWinLoseRate.second + myWinLoseRate.first));
        prev += winStreaks[i].length;
    }
    cout << fixed << setprecision(8) << ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
