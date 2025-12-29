#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 5000;
vector<ll> numberArray(MAX_N+5,-1);
vector<ll> numberArrayIndices(MAX_N+5,-1);

bool isInversion(ll a, ll b){
    return a > b;
}

void solve(){
    ll a;
    cin >> a;
    ll a2 = a;
    ll b;
    cin >> b;
    ll b2= b;
    // beyazla baslar
    bool nextLayerIsWhite = true;
    ll layerSize = 1;
    ll whiteStartLayers = 0;
    while(true){
        if(nextLayerIsWhite){
            if(a >= layerSize){
                a-=layerSize;
                whiteStartLayers++;
                nextLayerIsWhite = !nextLayerIsWhite;
            }
            else{
                break;
            }
        }
        else{
            if(b >= layerSize){
                b-=layerSize;
                whiteStartLayers++;
                nextLayerIsWhite = !nextLayerIsWhite;
            }
            else{
                break;
            }
        }
        layerSize = layerSize << 1;
    }
    nextLayerIsWhite = false;
    layerSize =1;
    ll blackStartLayers = 0;
    while(true){
        if(nextLayerIsWhite){
            if(a2 >= layerSize){
                blackStartLayers++;
                nextLayerIsWhite = !nextLayerIsWhite;
                a2 -= layerSize;
            }
            else{
                break;
            }
        }
        else{
            if(b2 >= layerSize){
                blackStartLayers++;
                nextLayerIsWhite = !nextLayerIsWhite;
                b2 -= layerSize;
            }
            else{
                break;
            }
        }
        layerSize = layerSize << 1;
    }
    cout << max(whiteStartLayers,blackStartLayers) << "\n";

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
