#include <bits/stdc++.h>
using namespace std;

#define ll long long 

vector<vector<tuple<ll, ll, ll>>> lastDigits = {
    {{0,0,0},{20,5,0}, {30,4,2}},//0
    {{11,1,1},{21,0,3}},//1
    {{12,3,0},{22,2,2},{32,1,4},{42,0,6}},//2
    {{23,4,1},{33,3,3}},//3
    {{4,1,0},{14,0,2},{24,6,0}},//4
    {{15,2,1},{25,1,3},{35,0,5}},//5
    {{16,4,0},{26,3,2},{36,2,4}},//6
    {{7,0,1},{27,5,1}},//7
    {{8,2,0},{18,1,2},{28,0,4}},//8
    {{19,3,1},{29,2,3},{39,1,5}}//9
};

bool getAns(ll n, stack<tuple<ll, ll>>& res){
    if(n == 0){
        res.push({0,0});
        return true;
    }
    else{
        ll lastDigit = n%10;
        for(auto [val, i, j] : lastDigits[lastDigit]){
            if(n >= val){
                res.push({i, j});
                if(getAns((n - val)/10, res)){
                    return true;
                }
                res.pop();
            }
        }
    }
    return false;
}

void solve(){
    ll n;
    cin >> n;
    stack<tuple<ll, ll>> res;
    vector<ll> solution(6,0);
    if(getAns(n,res)){
        while(!res.empty()){
            auto[i, j] =  res.top();
            res.pop();
            ll iter = 0;
            for(ll o = 0; o < 6; o++){
                solution[o] *=10;
            }
            for(; iter < i; iter++){
                solution[iter] +=4;
            }
            for(; iter < i+j; iter++){
                solution[iter] +=7;
            }
        }
        //ll sum = 0;
        for(ll i = 0; i < 6; i++){
            cout << solution[i] << " ";
           // sum += solution[i];            
        }
        cout << "\n";
    }
    else{
        cout << "-1\n";
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