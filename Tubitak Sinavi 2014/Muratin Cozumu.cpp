#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define rofeach(i,x) for(type(x)i=x.rbegin();i!=x.rend();i++)
#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define dbgs(x) cerr << (#x) << " --> " << (x) << ' '
#define dbg(x) cerr << (#x) << " --> " << (x) << endl
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)
#define type(x) __typeof(x.begin())
#define pii pair< int,int >
#define mod 1000000007
#define ll long long
#define pb push_back
#define mp make_pair
#define inf 1000000000
#define nd second
#define st first
#define endl '\n'

const int N = 1e5+5;
const int MAX = 1e9+5;

ll on[19],way[105],ans,i,j,k,n,m,dp[200][150];

string str;

vector< pair<int,pii> > v[105];

int f(int q,int x,int elde){

    int kalan=str[x]-'0'-elde;
    
    int t=0;

    if(kalan<0) kalan+=10,t=1;

    if(x==0){

        if( t ) return 0;
        if(kalan==7 || kalan==4 || kalan==0 ){ way[1]+=on[q]*kalan; return 1; }
        if(kalan==8){ way[1]+=on[q]*4; way[2]+=on[q]*4; return 1; }
        return 0;

    }

    if(dp[x][kalan]!=-1) return dp[x][kalan];

    dp[x][kalan]=0;

    ll way2[8]={0};

    FOR(i,0,(int)v[kalan].size()-1){

        FOR(j,1,6) way2[j]=way[j];
        
        FOR(j,1,v[kalan][i].nd.st) way[j]+=on[q]*7;
        FOR(j,1,v[kalan][i].nd.nd){ way[j+v[kalan][i].nd.st]+=on[q]*4; }
    
        dp[x][kalan]=f(q+1,x-1,v[kalan][i].st+t);
    
        if(dp[x][kalan]==1) return 1;

        FOR(j,1,6) way[j]=way2[j];

    }

    return dp[x][kalan];
    
}

int main(){

    scanf("%lld",&n);
    
    on[0]=1;

    FOR(i,1,18)
        on[i]=on[i-1]*10;
    
    FOR(i,0,6)
        FOR(j,0,6){
            if(i+j>6) continue;
            v[(7*i+4*j)%10].pb(mp((7*i+4*j)/10,mp(i,j)));
        }

    int tt=0;

    FOR(i,1,n){
    
        cin >> str;

        memset(dp,-1,sizeof dp);
        
        memset(way,0,sizeof way);

        if(f(0,str.size()-1,0)){
        
            FOR(i,1,6) cout << way[i] << ' ' ;
        
            cout << endl;
        
        }

        else cout << -1 << endl;
        
    }
    
    return 0;
}