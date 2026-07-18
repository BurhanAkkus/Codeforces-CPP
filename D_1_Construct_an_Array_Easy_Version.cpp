#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 1005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

bool matrix[MAX_N][MAX_N];
vector<ll> eksiler;
vector<ll> mutlakDegerSiralamasi;
array<set<ll>,MAX_N> bendenKucukPozitifler;
array<ll,MAX_N> sayilar;
void solve(){
    ll n,m;
    cin >> n >> m;
    eksiler.clear();
    mutlakDegerSiralamasi.clear();
    rep(i,0,n,1){
        bendenKucukPozitifler[i].clear();
        sayilar[i] = 1e9;
    }
    rep(i,0,m,1){
        ll o,l,m;
        cin >> o >> l >> m;
        matrix[l-1][m-1] = o == 1;
        matrix[m-1][l-1] = o == 1;
    }
    
    // + and + must combine to +
    // - and - must combine to -
    rep(i,0,n,1){
        rep(j,i+1,n,1){
            if(matrix[i][i] == matrix[j][j] && matrix[i][i] != matrix[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }
    
    rep(i,0,n,1){
        if(!matrix[i][i]){
            eksiler.push_back(i);
            rep(j,0,n,1){
                if(matrix[j][j] && !matrix[i][j]){
                    bendenKucukPozitifler[i].insert(j);
                }
            }
        }
    }
    
    if(eksiler.size() == 0 || eksiler.size() == n){
        cout << "YES\n";
        if(eksiler.size() == 0)
            rep(i,1,n+1,1){
                cout << i << " ";
            }
        else{
            rep(i,1,n+1,1){
            cout << -i << " ";
            }
        }
        cout << "\n";
        return;
    }

    sort(eksiler.begin(),eksiler.end(),[](ll a, ll b){
        return bendenKucukPozitifler[a].size() < bendenKucukPozitifler[b].size();
    });
    ll sayi = 1;

    rep(i,0,eksiler.size(),1){
        ll eksi = eksiler[i];
        for(auto eksidenKucukPozitif:bendenKucukPozitifler[eksi]){
            rep(j,i + 1,eksiler.size(),1){
                ll sonrakiEksi = eksiler[j];
                if(matrix[eksidenKucukPozitif][sonrakiEksi]){
                    cout << "NO\n";
                    return;
                }
                bendenKucukPozitifler[sonrakiEksi].erase(eksidenKucukPozitif);
            }
            sayilar[eksidenKucukPozitif] = sayi++;
        }
        sayilar[eksi] = -(sayi++);
    }
    cout << "YES\n";
    rep(i,0,n,1){
        cout << sayilar[i] << " ";
    }
    cout << "\n";


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}
