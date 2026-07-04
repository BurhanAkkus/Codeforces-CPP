#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 1000005;
const ll PRIME_COUNT_UNTIL_MAX_N = 80000;
vector <ll> primes;
int primeIndex[MAX_N] = {};  // direct lookup, no hashing

ll spf[MAX_N];  // spf[i] = smallest prime factor of i]
vector<ll> touched;

ll primeFactorCounts[PRIME_COUNT_UNTIL_MAX_N];

void precomputePrimes(){
    for(int i = 0; i < MAX_N; i++) spf[i] = i;
    for(int i = 2; (ll)i*i < MAX_N; i++)
        if(spf[i] == i)  // i is prime
        {
          for(int j = i*i; j < MAX_N; j += i)
              if(spf[j] == j) spf[j] = i;
        }
    for(int i = 2; i < MAX_N; i++)
        if(spf[i] == i) primes.push_back(i); 
    for(int i = 0; i < (int)primes.size(); i++) primeIndex[primes[i]] = i;
}

void primeFactorize(ll n){
    while(n > 1){
        int p = spf[n];
        primeFactorCounts[primeIndex[p]]++;
        if(primeFactorCounts[primeIndex[p]] == 1) touched.push_back(primeIndex[p]);
        n /= p;
    }
}


void solve(){
  ll n;
  cin >> n;
primeFactorize(n);
    ll sum = 0;
    ll count = 0;
    for(ll prime:touched){
        sum += primeFactorCounts[prime];
        count ++;
        primeFactorCounts[prime] = 0;
    }
    touched.clear();
    cout << sum + count - 1 << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputePrimes();
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
