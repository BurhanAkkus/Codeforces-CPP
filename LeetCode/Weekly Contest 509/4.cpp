#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 100005
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(int i=(start);i<(end);i+=(increment))

int p[2 * MAX_N + 3]{0};
int transformedNums[2*MAX_N + 3]{0};
ll transformedPrefixSums[2*MAX_N + 3]{0};
class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        rep(i,0,2*n+2,1) {
        transformedNums[i] = 0;
        transformedPrefixSums[i] = 0;
        p[i] = 0;
        }
        rep(i,0,n,1){
            transformedNums[i*2+1] = nums[i];
            transformedPrefixSums[i*2] = i > 0? transformedPrefixSums[i*2-1] : 0;
            transformedPrefixSums[i*2 + 1] = transformedPrefixSums[i*2] + nums[i];
        }
        transformedPrefixSums[2 * n] = transformedPrefixSums[2*n - 1];
        n = 2*n + 1;
        int c=0,r=0;
        rep(i,0,n,1){
            if(r > i){
                int mirror = 2*c-i;
                p[i] = min(r-i,p[mirror]);
            }
            // expand around i
            while(i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
            transformedNums[i + p[i] + 1] == transformedNums[i - p[i] - 1]){
                p[i]++;
            }
            if(i + p[i] > r){
                c = i;
                r = i+p[i];
            }
        }
        ll maxim = 0;
        rep(i,1,n,1){
            maxim = max(maxim,transformedPrefixSums[p[i] + i] - (i > p[i]? transformedPrefixSums[i-p[i] - 1]: 0));
        }
        return maxim;

        
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
    cout << solution.getSum(nums) << "\n";
}
