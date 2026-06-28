#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 1000002

vector <ll> primes;
int primeIndex[MAX_N] = {};
ll primeFactorCounts[80000]; 
ll spf[MAX_N];

vector<ll> touched;

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
        int idx = primeIndex[p];
        if(primeFactorCounts[idx] == 0) touched.push_back(idx);
        primeFactorCounts[idx]++;
        n /= p;
    }
}

void solve(){
    ll n;
    cin >> n;
    primeFactorize(n);
    ll sum = 0;
    ll count = 0;
    for(ll primeFactorIndex:touched){
        sum += primeFactorCounts[primeFactorIndex];
        count++;
        primeFactorCounts[primeFactorIndex] = 0;
    }
    touched.clear();

    cout << sum + count -1 <<"\n";

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
