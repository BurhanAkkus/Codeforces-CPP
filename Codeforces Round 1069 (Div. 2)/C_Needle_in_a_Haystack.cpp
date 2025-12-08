#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    getline(cin >> ws, s);
    string t;
    getline(cin >> ws, t);
    array<int, 256> freqs{};
    array<int, 256> freqt{};
    for (unsigned char ch : s) ++freqs[ch]; // cast to unsigned char to avoid negative indices
    for (unsigned char ch : t) ++freqt[ch]; // cast to unsigned char to avoid negative indices

    string newT = "";
    bool impossible = false;
    for (int i = 0; i < 256; ++i) {
        if(freqs[i] > freqt[i]) {
            impossible = true;
            break;
        }
        if (freqt[i] > 0) {
            newT += string(freqt[i] - freqs[i], static_cast<char>(i));
        }
    }
    if(impossible){
        cout << "Impossible\n";
        return;
    }
    long long currentMin = 0;
    for(char currentChar : s){
        while(currentMin <newT.length() && newT[currentMin] < currentChar){
            currentMin++;
        }
        newT.insert(newT.begin() + currentMin, currentChar);
        currentMin++;
    }
    cout << newT << "\n";
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