#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> bit;

// 0-indexed external position -> 1-indexed BIT position
void upd(int i, ll x){ for (i++; i <= n; i += i & -i) bit[i] += x; }
// sum of the first k elements (BIT positions 1..k)
ll pre(int k){ ll s = 0; for (; k > 0; k -= k & -k) s += bit[k]; return s; }

int main(){
    int T; scanf("%d", &T);
    while (T--){
        int q; scanf("%d %d", &n, &q);
        bit.assign(n + 1, 0);            // correct multitest reset
        while (q--){
            int t; scanf("%d", &t);
            if (t == 1){
                int i; ll x; scanf("%d %lld", &i, &x);
                upd(i, x);
            } else {
                int l, r; scanf("%d %d", &l, &r);
                printf("%lld\n", pre(r + 1) - pre(l - 1));
            }
        }
    }
    return 0;
}
// PLANTED BUG: range sum uses pre(r+1) - pre(l-1); correct is pre(r+1) - pre(l).
// Off-by-one on the low end double-counts index (l-1) whenever l >= 1; it stays
// hidden when l == 0 (pre(-1) == 0), so tiny/edge cases pass and only l>=1 exposes it.
