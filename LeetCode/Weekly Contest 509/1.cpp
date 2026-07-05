#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 1000000
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
const ll BITLEN = 3;
const ll BASE = 10;
vector<ll> make_pow (ll base, ll maxv) {
	vector<ll> ans(maxv+1, 0);
	ans[0] = 1;
	for (ll i = 1; i <= maxv; i++) {
		ans[i] = ans[i-1] * base;
	}
	return ans;
}
const vector<ll> pow10 = make_pow(BASE, BITLEN);
inline ll idxdigit (const ll x, const ll d) {
	return (x / pow10[d]) % BASE;
}
class Solution {
public:
    
    int maxDigitRange(vector<int>& nums) {
        ll maxRange = 0;
        ll answer = 0;
        rep(i,0,nums.size(),1){
            ll num = nums[i];
            if(maxRange == digitRange(num)){
                answer += num;
            }
            else if(maxRange < digitRange(num)){
                answer = num;
                maxRange = digitRange(num);
            }
        }
        return answer;
    }
    int digitRange(int num){
        int minim = 9;
        int maxim = 0;
        while(num > 0){
            minim = min(minim,num%10);
            maxim = max(maxim,num%10);
            num /=10;
        }
        return maxim-minim;
    }
    
};©leetcode