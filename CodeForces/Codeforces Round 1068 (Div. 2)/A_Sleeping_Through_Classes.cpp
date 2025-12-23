#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    // char array of size n
    vector<char> arr(static_cast<size_t>(n));
    for(long long i = 0; i < n; i++){
        cin >> arr[static_cast<size_t>(i)];
    }
    long long lastImportantIndex = -k *2;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == '1'){
            lastImportantIndex = i;
        }
        else{
            if(i - lastImportantIndex > k){
                ans++;
            }
        }
    }
    cout << ans << "\n";
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