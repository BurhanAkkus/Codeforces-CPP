#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    long long n;
    cin >> n;
    // long array of size n
    vector<long long> a(static_cast<size_t>(n));
    vector<long long> b(static_cast<size_t>(n));
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    for(long long i = 0; i < n; i++){
        cin >> b[i];
    }
    long long maxScore = max( - a[0], b[0] );
    long long minScore = min( - a[0], b[0] );
    for(long long i = 1; i < n; i++){
        long long prevMaxScore = maxScore;
        maxScore = max( {maxScore - a[i], minScore - a[i], b[i] - maxScore, b[i] - minScore});
        minScore = min( {prevMaxScore - a[i], minScore - a[i], b[i] - prevMaxScore, b[i] - minScore});
    }
    cout << maxScore << "\n";

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