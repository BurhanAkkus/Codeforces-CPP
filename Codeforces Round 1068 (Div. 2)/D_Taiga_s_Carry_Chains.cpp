#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    long long numberOfBits = 32;
    while(t--){
        long long n;
        cin >> n;
        long long k;
        cin >> k;
        vector<vector<array<long long,2>>> dp(
            static_cast<size_t>(numberOfBits),
            vector<array<long long,2>>(static_cast<size_t>(numberOfBits) + 1, array<long long,2>{0,0})
        );
        long long kyiNumberOfBitseTamamlayan = k > 32? k - 32:0;
        k = min(k,32LL);
        vector<int> bits(static_cast<size_t>(numberOfBits), 0);
        for(long long i = 0; i < numberOfBits; i++){
            bits[i] = n%2;
            n /= 2;
        }
        vector<int> solumdakiBirSayisi(static_cast<size_t>(numberOfBits), 0);
        int running1Count = 0;
        for(int i = numberOfBits - 1; i >= 0; i--){
            solumdakiBirSayisi[i] = running1Count;
            if(bits[i] == 1){
                running1Count++;
            }
            else{
                running1Count = 0;
            }
        }

        // 0 hamle produces 0 score
        for(int i = 0; i < numberOfBits; i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = 0;
        }
        // 31. biti hallet

        for(int hamle = 1; hamle < numberOfBits; hamle++){
            dp[numberOfBits - 1][hamle][0] = dp[numberOfBits - 1][hamle -1][1];
            dp[numberOfBits - 1][hamle][1] = hamle;
        }

        // define dp transitions
        // dp[bit][hamle][0] => max( dp[bit][hamle-1][1], dp[bit+1][hamle][bits[bit+1]] )
        // dp[bit][hamle][1] = max (solumdaki1Sayisi[bit]  + 1 + dp[bit+solumdaki1Sayisi + 1][hamle-1][1], dp[bit+1][hamle][bits[bit+1]]
        // start from the highest bit with lowest hamle
        for(int bit = numberOfBits -2; bit >=0; bit--){
            for(int hamle = 1; hamle <= min(k,numberOfBits); hamle++){
                dp[bit][hamle][0] = max( dp[bit][hamle-1][1] , dp[bit + 1][hamle][bits[bit+1]]);
                dp[bit][hamle][1] = max(solumdakiBirSayisi[bit] + 1 + dp[solumdakiBirSayisi[bit] + 1 + bit][hamle - 1][1], dp[bit + 1][hamle][bits[bit+1]]);
            }
        }
        
        cout<< dp[0][k][bits[0]] + kyiNumberOfBitseTamamlayan<< "\n";
    }
}
    