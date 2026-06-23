#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 998244353;
const ll MAX_N = 200002;

ll fact[MAX_N], inv_fact[MAX_N];

ll power(ll a, ll b, ll mod){
    ll res = 1; a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute(){
    fact[0] = 1;
    for(ll i = 1; i < MAX_N; i++) fact[i] = fact[i-1] * i % MOD;
    inv_fact[MAX_N-1] = power(fact[MAX_N-1], MOD-2, MOD);
    for(ll i = MAX_N-2; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
}

ll combination(ll n, ll k){
    if(k < 0 || k > n) return 0;
    return fact[n] % MOD * inv_fact[k] % MOD * inv_fact[n-k] % MOD;
}

// E[1 / (base + Binomial(trials, 1/2))] mod MOD
ll E_inv(ll base, ll trials){
    ll inv2_pow = power(power(2, trials, MOD), MOD-2, MOD);
    ll res = 0;
    for(ll j = 0; j <= trials; j++)
        res = (res + combination(trials, j) * power(base + j, MOD-2, MOD)) % MOD;
    return res * inv2_pow % MOD;
}

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    ll M = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        M = max(M, max(a[i], b[i]));
    }

    // Categorize matches relative to global max M
    // nt  = both players at M (TT): always produces one M+1 scorer
    // nTH = one at M, other at M-1: top wins -> M+1; top loses -> both score M
    // nf  = nTH + number of (top vs < M-1) matches = all matches with a top player (excluding TT)
    // nHH = both at M-1: winner scores M (relevant only if max final = M)
    // nHL = one at M-1, other < M-1: M-1 player winning scores M (relevant only if max final = M)
    ll nt = 0, nf = 0, nTH = 0, nHH = 0, nHL = 0;
    for(int i = 0; i < n; i++){
        ll mx = max(a[i], b[i]), mn = min(a[i], b[i]);
        if     (mx == M   && mn == M  )  nt++;
        else if(mx == M   && mn == M-1){ nf++; nTH++; }
        else if(mx == M              )   nf++;
        else if(mx == M-1 && mn == M-1)  nHH++;
        else if(mx == M-1            )   nHL++;
    }

    ll inv2 = power(2, MOD-2, MOD);
    vector<ll> ans(2*n, 0);

    if(nt > 0){
        // TT match guarantees max final = M+1 always.
        // Non-top players can score at most M -> P = 0.
        //
        // Top player in TT match:
        //   Given p wins: M+1 scorers = (nt-1) other TT winners + 1(p) + Bin(nf, 1/2) TO winners
        //                             = nt + Bin(nf, 1/2)
        //   P = (1/2) * E[1 / (nt + Bin(nf, 1/2))]
        //
        // Top player in TO match (TH or TL):
        //   Given p wins: M+1 scorers = nt TT winners + 1(p) + Bin(nf-1, 1/2) other TO winners
        //                             = nt+1 + Bin(nf-1, 1/2)
        //   P = (1/2) * E[1 / (nt+1 + Bin(nf-1, 1/2))]
        ll p_TT = inv2 * E_inv(nt, nf) % MOD;
        ll p_TO = nf > 0 ? inv2 * E_inv(nt + 1, nf - 1) % MOD : 0;

        for(int i = 0; i < n; i++){
            ll mx = max(a[i], b[i]), mn = min(a[i], b[i]);
            if(mx == M && mn == M){
                ans[2*i] = p_TT; ans[2*i+1] = p_TT;
            } else if(mx == M){
                (a[i] == M ? ans[2*i] : ans[2*i+1]) = p_TO;
            }
        }
    } else {
        // No TT matches. Every top player (score M) is in a TO match.
        // k = nf = number of top players.
        // Max final = M+1 w.p. 1-(1/2)^k (at least one top wins),
        //           = M    w.p. (1/2)^k   (all top players lose).
        ll k = nf;
        ll inv2k = power(power(2, k, MOD), MOD-2, MOD);

        // When max=M, M-scorers = k top losers + nTH TH-non-top winners + nHH HH winners
        //                         + Bin(nHL, 1/2) HL M-1 winners
        ll E_base = E_inv(k + nTH + nHH, nHL);

        // Top player p:
        //   Winning path (max=M+1): P = (2^k-1) / (k * 2^k)
        //     [derived via sum C(k-1,j)/(j+1) = (2^k-1)/k]
        //   Losing path (max=M, all k top lose): P = (1/2)^k * E_base
        ll p_top_win  = (power(2, k, MOD) - 1 + MOD) % MOD
                      * power(k % MOD * power(2, k, MOD) % MOD, MOD-2, MOD) % MOD;
        ll p_top_lose = inv2k * E_base % MOD;
        ll p_top      = (p_top_win + p_top_lose) % MOD;

        // TH non-top player (score M-1): given max=M they won for free.
        //   P = (1/2)^k * E_base  (same denominator as top's losing path)
        ll p_TH_nontop = p_top_lose;

        // HH player (both M-1): wins w.p. 1/2, scores M. Denominator unchanged (nHH is fixed).
        //   P = (1/2)^k * (1/2) * E_base
        ll p_HH = inv2 * p_top_lose % MOD;

        // HL M-1 player: wins w.p. 1/2, scores M. Denominator increases by 1 (vs E_base).
        //   P = (1/2)^k * (1/2) * E[1/(k+nTH+nHH+1 + Bin(nHL-1, 1/2))]
        ll p_HL = nHL > 0
                ? inv2k * inv2 % MOD * E_inv(k + nTH + nHH + 1, nHL - 1) % MOD
                : 0;

        for(int i = 0; i < n; i++){
            ll mx = max(a[i], b[i]), mn = min(a[i], b[i]);
            if(mx == M){
                if(a[i] == M){
                    ans[2*i]   = p_top;
                    ans[2*i+1] = (b[i] == M-1) ? p_TH_nontop : 0;
                } else {
                    ans[2*i]   = (a[i] == M-1) ? p_TH_nontop : 0;
                    ans[2*i+1] = p_top;
                }
            } else if(mx == M-1 && mn == M-1){
                ans[2*i] = p_HH; ans[2*i+1] = p_HH;
            } else if(mx == M-1){
                if(a[i] == M-1) ans[2*i] = p_HL;
                else            ans[2*i+1] = p_HL;
            }
        }
    }

    for(int i = 0; i < 2*n; i++) cout << ans[i] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    solve();
}
