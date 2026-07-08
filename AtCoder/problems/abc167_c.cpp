#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define MAX_N 12

ll prices[MAX_N];
ll bookSkillMatrix[MAX_N][MAX_N];

ll skillMatrix[MAX_N];
void solve(){
    ll n,m,x;
    cin >> n >>m >> x;
    rep(i,0,n,1){
        cin >> prices[i];
        rep(j,0,m,1){
            cin >>bookSkillMatrix[i][j];
        }
    }
    ll minCost = Infinity;
    rep(i,0,1<<12,1){
        ll cost = 0;
        rep(j,0,m,1){
            skillMatrix[j] = 0;
        }
        rep(bit,0,n,1){
            if(1 << bit & i){
                cost += prices[bit];
                rep(j,0,m,1){
                    skillMatrix[j] += bookSkillMatrix[bit][j];
                }
            }
        }
        bool flag= true;
        rep(j,0,m,1){
            if(skillMatrix[j] < x){
                flag = false;
                break;
            }
        }
        if(flag){
            minCost = min(minCost,cost);
        }
    }
    if(minCost == Infinity){
        cout << "-1";
        return;
    }
    cout << minCost;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
