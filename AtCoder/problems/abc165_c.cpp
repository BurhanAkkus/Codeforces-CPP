#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define MAX_N 11
#define MAX_M 11
#define MAX_Q 51

ll Q[MAX_Q][4];
int sayilar[MAX_N];

ll n,m,q;
ll maxScore = 0;
vector<int> sayilar2;

void solve(){
    ll n,m,q;
    cin >> n >> m >> q;
    rep(i,0,q,1){
        cin >> Q[i][0] >>  Q[i][1] >>  Q[i][2] >>  Q[i][3];
    }
    ll maxScore = 0;

    rep(i,0,1 << (m+n - 2),1){
        int oneCountSum = 0;
        int zeroCountSum = 0;
        int oneCount = 0;
        int zeroCount = 0;
        rep(j,0,n,1){
            sayilar[j] = 0; 
        }
        ll score = 0;
        bool validFlag = true;
        rep(digit,0,m+n - 2,1){
            if((1 << digit) & i){
                oneCount++;
                if(oneCount == m){
                    validFlag = false;
                    break;
                }
            }
            else{
                sayilar[++zeroCount] = oneCount;
                if(zeroCount == n -1){
                    break;
                }
            }
        }
        if(validFlag){
            rep(qq,0,q,1){
                ll ai = Q[qq][0] - 1;
                ll bi = Q[qq][1] - 1;
                ll ci = Q[qq][2];
                ll di = Q[qq][3];
                if(sayilar[bi] - sayilar[ai] == ci){
                    score+=di;
                }
            }
            maxScore = max(maxScore,score);
        }
    }
    cout<< maxScore;
}

ll calculateScore(){
    ll score = 0;
    rep(qq,0,q,1){
        ll ai = Q[qq][0] - 1;
        ll bi = Q[qq][1] - 1;
        ll ci = Q[qq][2];
        ll di = Q[qq][3];
        if(sayilar2[bi] - sayilar2[ai] == ci){
            score+=di;
        }
    }
    return score;
}

ll dfs(int last){
    if(sayilar2.size() == n){
        return calculateScore();
    }
    ll score = 0;
    rep(next,last,m + 1,1){
        sayilar2.push_back(next);
        score = max(score,dfs(next));
        sayilar2.pop_back();
    }
    return score;   
}


void solve2(){
    cin >> n >> m >> q;
    rep(i,0,q,1){
        cin >> Q[i][0] >>  Q[i][1] >>  Q[i][2] >>  Q[i][3];
    }

    cout<< dfs(1);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    //cin >> t;
    while(t--){
        solve2();
    }
}
