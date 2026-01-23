#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
const long long MAX_N = 100;

vector<char> numberArray(MAX_N+5,-1);

bool sendQuery(int i, int j){
    cout << "? "<<  i << " " << j << "\n";
    cout.flush();
    char ans;
    cin >> ans;
    return ans == '1';
}

void solve(){
    ll n;
    cin >> n;
    ll k = n - 1;
    while( k > 1 && sendQuery(k,k+1)){
        k--;
    }
    if(k == 1){
        cout << "! -1\n";
        cout.flush();
        return;
    }
    // k - 1 < k
    if(sendQuery(k - 1,k)){
        string out = "! ";
        for(ll j = 1; j < k - 1; j++){
            out.append(to_string(j) + " ");
        }
        vector<ll> ranking;
        ranking.push_back(k+1);
        ll iter = k+2;
        while(iter <= n && !sendQuery(k,iter)){
            ranking.push_back(iter);
            iter++;
        }
        ranking.push_back(k);
        while(iter <= n){
            ranking.push_back(iter++);
        }
        // n > n-1 > n-2 > .... k > .... > k + 1
        iter = 0;
        while(ranking[iter] != k && !sendQuery(k-1,ranking[iter])){
            iter++;
        }
        out.append(to_string(ranking[iter]) + " ");
        ranking[iter] = k-1;
        for(ll j = 0; j < ranking.size(); j++){
            out.append(to_string(ranking[j]) + " ");
        }
        cout << out << "\n";
        cout.flush();
        return;
    }
    // k - 1 > k
    // k-1 > n > n-1> n-2...> k > .... > k + 1
    if(!sendQuery(k-1,n)){
        ll i = k-2;
        while(i > 0 && !sendQuery(i,i+1)){
            i--;
        }
        if( i == 0){
            cout << "! -1\n";
            cout.flush();
            return;
        }
        string out = "! ";
        // i+1 > i+2 > i+3 ... k - 1 > n > n-1 ... > k + 1
        // i+1 > i
        // k > k+1
        // k - 1 > k
        // k - 1 > n > n - 1 > n - 2 ... > k + 1
        vector<ll> ranking;
        // insert k.
        bool addedK = false;
        ranking.push_back(k+1);
        for(ll j = k + 2; j <=n; j++){
            if(!addedK){
                if(sendQuery(k,j)){
                    ranking.push_back(k);
                    addedK = true;
                }
            }
            ranking.push_back(j);
        }
        if(!addedK){
            ranking.push_back(k);
        }
        for(ll j = k - 1; j > i; j--){
            ranking.push_back(j);
        }
        // insert i
        ll iter = 0;
        while(iter < ranking.size() - 1 && !sendQuery(i,ranking[iter])){
            iter++;
        }
        out.append(to_string(ranking[iter]) + " ");
        ranking[iter] = i;
        for(auto rank:ranking){
            out.append(to_string(rank) + " ");
        }
        cout << out << "\n";
        cout.flush();
        return;
    }
    
    // n > k-1 > k > k + 1
    ll i = k - 2;
    while( i > 0 && !sendQuery(i,i+1)){
        i--;
    }
    
    if(i == 0){
        cout<< "! -1\n";
        cout.flush();
        return;
    }
    string out = "! ";
    // print until i
    for(ll j = 1; j < i; j++){
        out.append(to_string(j) + " ");
    }
    vector<ll> ranking;
    ranking.push_back(k+1);
    ll iterLeft = k;
    ll iterRight = k+2;
    while(iterLeft > i && iterRight <= n){
        if(sendQuery(iterLeft,iterRight)){
            ranking.push_back(iterLeft--);
        }
        else{
            ranking.push_back(iterRight++);
        }
    }
    while(iterLeft > i){
        ranking.push_back(iterLeft--);
    }
    while( iterRight <= n){
        ranking.push_back(iterRight++);
    }
    ll iter = 0;
    while(ranking[iter] != i+1 && !sendQuery(i,ranking[iter])){
        iter++;
    }
    out.append(to_string(ranking[iter]) + " ");
    ranking[iter] = i;
    for(auto rank:ranking){
        out.append(to_string(rank) + " ");
    }
    cout << out << "\n";
    cout.flush();
    return;
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
