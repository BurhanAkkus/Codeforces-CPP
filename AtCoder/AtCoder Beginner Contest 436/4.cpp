#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll h;
    cin >> h;
    ll w;
    cin >> w;
    vector<vector<char>> map(h,vector<char>(w));
    vector<vector<pair<ll,ll>>> warps(26,vector<pair<ll,ll>>(0));
    vector<bool> goneToWarp(26,false);

    for(ll i = 0; i < h; i++){
        for(ll j= 0; j< w;j++){
            cin >> map[i][j];
            if(map[i][j] != '.' && map[i][j] != '#'){
                warps[map[i][j] - 'a'].push_back({i,j});
            }
        }
    }
    vector<vector<ll>> distance(h,vector<ll>(w,-1));
    distance[0][0] = 0;
    queue<pair<ll,ll>> toVisit;
    toVisit.push({0,0});
    pair<ll,ll> directions[4]{{-1,0},{1,0},{0,-1},{0,1}};
    while(!toVisit.empty()){
        pair<ll,ll> current = toVisit.front();
        toVisit.pop();
        ll currentX = current.first;
        ll currentY = current.second;
        char currentChar = map[currentX][currentY];
        // 4 directions
        for(int i = 0; i < 4; i++){
            pair<ll,ll> direction = directions[i];
            if(currentX + direction.first >=0 && currentX + direction.first < h && currentY + direction.second >=0 && currentY + direction.second < w 
                && map[currentX + direction.first][currentY + direction.second] != '#'
                 && distance[currentX+ direction.first][currentY + direction.second] == -1){
                    distance[currentX+ direction.first][currentY + direction.second] = distance[currentX][currentY] +1;
                    toVisit.push({currentX+ direction.first,currentY + direction.second});
                 }
        }
        if(map[currentX][currentY] != '.' && map[currentX][currentY] != '#'){
            if(!goneToWarp[map[currentX][currentY] - 'a']){
                vector<pair<ll,ll>> warpsToGo = warps[map[currentX][currentY] - 'a'];
                for(auto warpToGo : warpsToGo){
                    if(distance[warpToGo.first][warpToGo.second] == -1){
                        distance[warpToGo.first][warpToGo.second] = distance[currentX][currentY] +1;
                        toVisit.push({warpToGo.first,warpToGo.second});
                    }
                }
                goneToWarp[map[currentX][currentY] - 'a'] = true;
            }
        }
    }
    cout << distance[h-1][w-1];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}