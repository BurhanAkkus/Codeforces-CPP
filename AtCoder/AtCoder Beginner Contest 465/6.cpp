#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 1000000
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll z[MAX_N + 1]{0};
const ll BITLEN = 6;
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
void solve(){
    ll n;
    cin >> n;
    rep(i, 0, n, 1){
        ll s,v;
        cin >> s >> v;
        z[s] = v;
    }
    rep(bit,0,6,1){
        rep(i,0,MAX_N+1,1){
            if(idxdigit(i,bit) != 0){
                z[i] += z[i - pow10[bit]];
            }
        }
    }
    ll q;
    cin >> q;
    rep(i,0,q,1){
        ll x,y;
        ll ans = 0;
        bool flag = true;
        cin >> x >> y;
        rep(bit,0,6,1){
                if(idxdigit(x,bit) > idxdigit(y,bit)){
                    flag = false;
                    break;
                }
            }
        if(!flag){
            cout << 0 << "\n";
            continue;
        }
        rep(mask,0,64,1){
            ll criteria = 0;
            bool contributes = true;
            rep(bit,0,6,1){
                if((mask >> bit) & 1){
                    if(idxdigit(x,bit) == 0){
                        contributes = false;
                        break;
                    }
                    criteria += pow10[bit] * (idxdigit(x,bit) - 1) ;
                }
                else{
                    criteria += pow10[bit] * idxdigit(y,bit);
                }
            }
            if(!contributes) continue;
            ans +=  (1 - 2 * (__builtin_popcount(mask) % 2)) * z[criteria];
            
        }
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
