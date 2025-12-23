#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    // set for previously used colors
    set<long long> used_colors = {};
    long long color;
    for(long long i = 0; i < n; i++){
        cin >> color;
        used_colors.insert(color);
    }
    long long next = used_colors.size();
    while(true){
        if(used_colors.find(next) != used_colors.end()){
            break;
        }
        else{ 
            next++;
        }
    }
    cout<< next << "\n";
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