#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    // long array of size n
    vector<long long> a(static_cast<size_t>(n));
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    // empty vector to store b
    vector<long long> b;
    // set to check if element of a has been processed before
    set<long long> processed;
    // set of elements in a for quick lookup
    set<long long> elements(a.begin(), a.end());
    // sort a
    sort(a.begin(), a.end());
    bool minus1 = false;
    for(long long i = 0; i < n && !minus1; i++){
        if(processed.find(a[i]) != processed.end()){
            continue;
        }
        else{
            b.push_back(a[i]);
            for(long long j = a[i]; j <= k; j+=a[i]){
                if(elements.find(j) == elements.end()){
                    minus1 = true;
                    break;
                }
                else{
                    processed.insert(j);
                }
            }
        }
    }

    if(minus1){
        cout << -1 << "\n";
    }
    else{
        cout<< (int)(b.size()) << "\n";
        for(long long i = 0; i < (int)(b.size()); i++){
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    
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