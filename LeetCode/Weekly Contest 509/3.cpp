#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 1000100
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

int spf[MAX_N];

void precomputePrimes(){
    if(spf[2] != 0) return;                   // sieve once (guards repeated calls)
    for(int i = 0; i < MAX_N; i++) spf[i] = i;
    for(int i = 2; (ll)i*i < MAX_N; i++)
        if(spf[i] == i)                       // i is prime
            for(int j = i*i; j < MAX_N; j += i)
                if(spf[j] == j) spf[j] = i;
}

class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        precomputePrimes();
        int n = nums.size();

        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        unordered_map<int, vector<int>> pos;
        ll minim = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            minim = min(minim, (ll)nums[i]);
            int t = nums[i];
            while (t > 1) { int p = spf[t]; pos[p].push_back(i); while (t % p == 0) t /= p; }
        }

        ll bestDiff = -minim;
        int bestK = 2;
        for (auto& kv : pos) {
            int p = kv.first;
            const vector<int>& ps = kv.second;
            ll cur = 0, best = LLONG_MIN;
            int prev = -1;
            for (int j : ps) {
                ll gap = (prev >= 0) ? (pre[j] - pre[prev + 1]) : 0;
                cur = max((ll)nums[j], cur - gap + nums[j]);
                best = max(best, cur);
                prev = j;
            }
            if (best > bestDiff || (best == bestDiff && p < bestK)) {
                bestDiff = best;
                bestK = p;
            }
        }

        const ll MOD = 1000000007;
        return ((bestDiff % MOD * (bestK % MOD)) % MOD + MOD) % MOD;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n;
    cin >> n;
    vector<int> nums(n);
    rep(i,0,n,1){
        cin >> nums[i];
    }
    cout << solution.divisibleGame(nums) << "\n";
}
