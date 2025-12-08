#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long l;
    cin >> l;
    long long r;
    cin >> r;
    long long toPrint = 1;
    // set for already used prefix xors
    set<long long> prefixXors;
    
    long long xorValue = 0;
    long long araXor = 0;
    for(long long i = 1; i < r;i++){
        while(prefixXors.find(toPrint) != prefixXors.end()){
            toPrint++;
        }
        cout << toPrint << " ";
        xorValue ^= toPrint;
        if(i >= l){
            araXor ^= toPrint;
        }
        prefixXors.insert(xorValue);
        toPrint++;
    }
    cout << araXor << " ";
    prefixXors.insert(xorValue ^ araXor);
    prefixXors.insert(araXor);
    for(long long i = r; i < n;i++){
        while(prefixXors.find(toPrint) != prefixXors.end()){
            toPrint++;
        }
        cout << toPrint << " ";
        xorValue ^= toPrint;
        prefixXors.insert(xorValue);
        toPrint++;
    }
    cout<< "\n";
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