    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    #define MAX_N 200002
    #define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
    #define Infinity LONG_LONG_MAX

    array<vector<int>,26> alphabetIndices;

    // returns the first element i such that array[i] >= element
    ll lower_bound_custom(vector<int>& array, ll n, ll element){
        // answer lies [l,r), r is excluded.
        ll l = 0;
        ll r = n;
        while(l < r){
            ll mid = l + (r - l) /2; // rounds down.
            // answer can't be in mid.
            if(array[mid] < element) {l = mid + 1;} // shrinks the interval [l,r) 
            else{
                r = mid; // shrinks the interval.
            }
        }
        return l;
    }

    int countIndicesAfter(int alphabetIndex,int index){
        return alphabetIndices[alphabetIndex].size() - 
        lower_bound_custom(alphabetIndices[alphabetIndex],alphabetIndices[alphabetIndex].size(),index) + 1;
    }
    void solve(){

        ll n,l,r;
        cin >> n >> l >> r;
        string s;
        cin >> s;
        rep(i,0,n,1){
            alphabetIndices[s[i]-'a'].push_back(i);
        }
        ll ans = 0;
        rep(harf,0,26,1){
            rep(i,0,alphabetIndices[harf].size(),1){
                ans+= countIndicesAfter(harf,alphabetIndices[harf][i]+l)
                - countIndicesAfter(harf,alphabetIndices[harf][i]+r+1);
            }
        }
        cout << ans;
    }


    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll t = 1;
        // cin >> t;
        while(t--){   
            solve();
        }
    }