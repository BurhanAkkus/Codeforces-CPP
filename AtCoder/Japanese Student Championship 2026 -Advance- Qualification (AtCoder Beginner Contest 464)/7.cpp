#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;


void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> ans(n+1);
    if(n % 2 == 0){
        vector<ll> ops(n);
        ll count = 0;
        ll score = 0;
        for(int i = 0; i < n; i++){
            char olmasiGereken = i%2 == 0? 'R' : 'S';
            if(s[i] != olmasiGereken){
                count++;
                ops[i] = olmasiGereken == 'R'? 2:1;
            }
        }
        for(int i =0; i < n-1; i++){
            if(s[i] == 'R' && s[i+1] == 'S'){
                score++;
            }
        }
        // [0] = 2,0, [1] = 2,1, [2] = 0,1
        ll opCounts[3]={};
        for(int i = 0; i < n - 1; i++){
            if(ops[i] == 2 && ops[i + 1] == 0){
                opCounts[0]++;
            }
            else if(ops[i] == 2 && ops[i+1] == 1){
                opCounts[1]++;
            } 
            else if(ops[i] == 0 && ops[i + 1] == 1){
                opCounts[2]++;
            }
        }
        // k >= count -> optimum answer
        for(int i = count; i <=n; i++){
            ans[i] = n/2;
        }
        //  count - doubleOptCount * 2 <= k < count
        for(int doubleOpCount = 1; doubleOpCount <= opCounts[1]; doubleOpCount++){
            ans[count - doubleOpCount * 2 + 1] = ans[count] - doubleOpCount;
            ans[count - doubleOpCount * 2] = ans[count] - doubleOpCount;
        }
        // k <= count - doubleOptCount, each op removes 1 point of happiness.
        
        for(int i = 0; i <= n; i++)
        cout<< ans[i] << " ";
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
    solve();
    }
}