#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define MAX_N2 20002
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>

bool visited[MAX_N]{false};
ll dist[MAX_N];

array<vector<int>,MAX_N> edges;

void BFS1(int root){
    rep(i,0,MAX_N,1){
        dist[i] = Infinity;
        visited[i] = false;
    }
    dist[root] = 0;
    visited[root] = true;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dist[root],root});
    while(!pq.empty()){
        auto [d,source] = pq.top();
        pq.pop();
        for(auto& neighbor : edges[source]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                dist[neighbor] = dist[source] + 1;
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
}

char map_[MAX_N2][MAX_N2];

bool traversable(int x,int y){
    return map_[x][y] == '.';
}

ll dist2[MAX_N2][MAX_N2];
bool visited2[MAX_N2][MAX_N2];

int directions[4][2]{{+1,0},{-1,0},{0,+1},{0,-1}};
ll BFS2(int rootX,int rootY ,int destinationX,int destinationY){
    rep(i,0,MAX_N2,1){
        rep(j,0,MAX_N2,1){
        dist2[i][j] = Infinity;
        visited2[i][j] = false;
        }
    }
    dist2[rootX][rootY] = 0;
    visited2[rootX][rootY] = true;
    ll sourceIndex = rootX * MAX_N + rootY;
    queue<pair<int,int>> q;
    q.push({rootX,rootY});
    while(!q.empty()){
        auto [sourceX,sourceY] = q.front();
        q.pop();
        rep(direction,0,4,1){
            auto [xIncrement,yIncrement] = directions[direction];
            if(sourceX + xIncrement >= 0 && sourceX + xIncrement < MAX_N && sourceY + yIncrement >= 0 && sourceY + yIncrement < MAX_N
            && !visited2[sourceX+ xIncrement][sourceY+yIncrement]
            && traversable( sourceX + xIncrement, sourceY + yIncrement)){
                dist2[sourceX + xIncrement][sourceY+yIncrement] =
                    min(dist2[sourceX + xIncrement][sourceY+yIncrement],
                    dist2[sourceX][sourceY] + 1);
                q.push({sourceX + xIncrement,sourceY+yIncrement});
                visited2[sourceX + xIncrement][sourceY+yIncrement] = true;
            }
        }
    }
    return dist2[destinationX][destinationY] == Infinity? -1 : dist2[destinationX][destinationY];
}

int main(){
}
