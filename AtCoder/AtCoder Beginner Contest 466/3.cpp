#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


bool askQuery(int l, int r){
    cout << "? "<< l << " " << r << endl;
    string answer;
    cin >> answer;
    return answer[0] == 'Y';
}

void answerQuery(ll answer){
    cout << "! "<< answer << endl;
}

void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    ll l = 1;
    ll r = 2;
    ll ansL = 0;
    while(r <= n){
        if(askQuery(l,r)){
            ansL++;
            r++;
        }
        else{
            ans += ansL;
            ansL = max(0LL,ansL-1);
            l++;
            if(l == r){
                r++;
            }
        }
    }
    rep(i,l,n,1){
        ans+= ansL;
        ansL = max(ansL-1,0LL);
    }
    answerQuery(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}