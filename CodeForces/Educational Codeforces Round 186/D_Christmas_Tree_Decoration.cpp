#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
const long long MAX_N = 5000;

long long mod_pow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long mod_inv(long long y) {
    // mod must be prime, and y % mod != 0
    return mod_pow(y, MOD - 2);
}

ll combination(ll n, ll c){
    ll ans = 1;
    for(ll i = 1; i<=c; i++){
        ll iModInverse  = mod_inv(i);
        ans *= n-i +1;
        ans %= MOD;
        ans *= iModInverse;
        ans %= MOD;
    }
    return ans;
}

ll permutation(ll n){
    ll ans = 1;
    for( ll i = 1; i <=n; i++){
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll a0;
    cin >> a0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if( n == 1){
        cout <<1 << "\n";
        return;
    }
    vector<ll> prefixSum(n);
    prefixSum[0] = a[0];
    for(ll i = 1; i < n; i++){
        prefixSum[i]= prefixSum[i-1] + a[i];
    }

    ll esitlenecek = 0;
    for(; esitlenecek < n - 1; esitlenecek++){
        if(a0 < (esitlenecek +1) * a[esitlenecek + 1] - prefixSum[esitlenecek]){
            break;
        }
    }

    // hepsini a[esitlenecek] e esitledim.
    for(ll i = 0; i < esitlenecek; i++){
            a0-= a[esitlenecek] - a[i]; 
            a[i] = a[esitlenecek];
    }
    //hepsine esit dagit
    ll dagitilacak = a0 / (esitlenecek +1);
    a0 -= dagitilacak * (esitlenecek +1);
    for(ll i = 0; i <= esitlenecek; i++){
        a[i] += dagitilacak;
    }
    // fark max 1 olmali
    if(a[n-1] - a[0] > 1){
        cout << 0 << "\n";
        return;
    }

    //fark max 1.
    // kacc tane minimumdan maxa gecirebilirim?
    // c(esitlenecek,a0)
    ll a0IKaFarkliSekildeDagitirim = combination(esitlenecek+1,a0);
    ll maxSayisi = n - esitlenecek - 1 + a0;
    ll minSayisi = n - maxSayisi;
    ll ans = ((a0IKaFarkliSekildeDagitirim * permutation(maxSayisi) % MOD) * permutation(minSayisi)) % MOD;
    cout << ans<< "\n";

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
