
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<char> s(n);
    vector<char> t(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> t[i];
    }
    // get sOps
    int p = -1;
    vector<pair<int,int>> sOps;
    for(int i = 0; i < n -1; i++){
      if(s[i] == s[i+1]){
        p = i;
        break;
      }
    }
    if(p == -1){
      sOps.push_back({1,3});
      s[1] = '1'-s[1] + '0';
      s[2] = '1'-s[2] + '0';
      s[3] = '1'-s[3] + '0';
      p=0;
    }
    int L,R;
    R = p+1;
    L = p;
    char value = s[p];
    while(R < n){
      if(s[R] == value){
        R++;
      }
      else{
        sOps.push_back({L,R - 1});
        value = s[R];
        R++;
      }
    }
    L--;
    while(L >= 0){
      if(s[L] == value){
        L--;
      }
      else{
        sOps.push_back({L+1,R-1});
        value = s[L];
        L--;
      }
    }
    if(value == '1'){
      sOps.push_back({0,n-1});
    }
    // get tOps
    vector<pair<int,int>> tOps;
    p = -1;
    for(int i = 0; i < n -1; i++){
      if(t[i] == t[i+1]){
        p=i;
        break;
      }
    }
    if(p == -1){
      tOps.push_back({1,3});
      t[1] = '1'-t[1] + '0';
      t[2] = '1'-t[2] + '0';
      t[3] = '1'-t[3] + '0';
      p = 0;
    }

    R = p+1;
    L = p;
    
    value = t[p];
    while(R < n){
      if(t[R] == value){
        R++;
      }
      else{
        tOps.push_back({L,R - 1});
        value = t[R];
        R++;
      }
    }
    L--;
    while(L >= 0){
      if(t[L] == value){
        L--;
      }
      else{
        tOps.push_back({L+1,R - 1});
        value = t[L];
        L--;
      }
    }
    if(value == '1'){
      tOps.push_back({0,n-1});
    }
    cout << (int)(sOps.size() + tOps.size()) << '\n';
    for (auto &pr : sOps) {
      cout << (pr.first + 1) << ' ' << (pr.second + 1) << '\n';
    }
    for (int i = (int)tOps.size() - 1; i >= 0; --i) {
      auto &pr = tOps[i];
      cout << (pr.first + 1) << ' ' << (pr.second + 1) << '\n';
    }
  }
  return 0;
}
