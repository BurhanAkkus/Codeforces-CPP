#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 10000007
#define MAX_K 25
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
struct Deque{
    private:
    size_t capacity{16192};
    size_t _front;
    size_t _back;
    vector<T> q;
    public:
    Deque():_front{capacity + 1},_back{},q(capacity){};
    
    bool isEmpty(){
        return _front == capacity + 1;
    }
    bool isFull(){
        return (_front == 0 && _back == capacity - 1) || _back + 1 == _front;
    }
    bool hasSingleElement(){
        return _front == _back;
    }

    void clear(){
        _front = capacity + 1;
    }
    T front(){
        assert(!isEmpty());
        return q[_front];
    }
    T back(){
        assert(!isEmpty());
        return q[_back];
    }

    void resize(){
        size_t newCapacity = capacity * 2;
        vector<T> newQ(newCapacity);
        size_t iter = 0;
        while(!hasSingleElement()){
            newQ[iter++] = popFront();
        }
        newQ[iter] = front();
        _front = 0;
        _back = iter;
        capacity = newCapacity;
        q = newQ;
    }

    void initialize(T element){
            q[0] = element;
            _front = 0;
            _back = 0;
            return;
    }

    void insertFront(T element){
        //uninitialized
        if(_front == capacity + 1){
            return initialize(element);
        }
        // check if there is space
        if(isFull()){
            resize();
        }
        // insert into _front - 1.
        _front = _front == 0 ? capacity - 1 : _front - 1;
        q[_front] = element;
    }
    void insertBack(T element){
        // uninitialized
        if(_front == capacity + 1){
           return initialize(element);
        }
        // check if there is space
        if(isFull()){
            resize();
        }
        _back = _back == capacity - 1? 0 : _back + 1;
        q[_back] = element;
    }
    
    T popFront(){
        assert(!isEmpty());
        T frontElement = front();
        if(hasSingleElement()){_front = capacity + 1;}
        else if(_front == capacity - 1){_front = 0; }
        else {_front++;}
        return frontElement;
    }
    T popBack(){
        assert(!isEmpty());
        T backElement = back();
        if(hasSingleElement()){_front = capacity + 1;}
        else if(_back == 0){_back = capacity - 1; return backElement;}
        else {_back--;}
        return backElement;
    }
};


Deque<ll> q;

void insert(ll element){
    while(!q.isEmpty() && q.back() > element){
        q.popBack();
    }
    q.insertBack(element);
}

void remove(ll element){
    if(q.front() == element){
        q.popFront();
    }
}

array<ll,MAX_N> arr{};

void solve(){
    q.clear();
    ll n,k;
    cin >> n >> k;
    ll x,a,b,c;
    cin >> x >> a >> b >> c;
    arr[0] = x;
    rep(i,1,n,1){
        arr[i] = (arr[i-1] * a + b) % c;
    }
    rep(i,0,k,1){
        insert(arr[i]);
    }
    ll ans = 0;
    rep(i,k,n,1){
        ans ^= q.front();
        remove(arr[i-k]);
        insert(arr[i]);
    }
    ans ^= q.front();
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while(t--){
    solve();
    }
}
