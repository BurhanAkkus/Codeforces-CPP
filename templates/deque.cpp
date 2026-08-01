#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 10000007
#define MAX_N2 20002
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>
using namespace std;


array<ll,MAX_N> arr{};

template<typename T>
struct Deque{
    private:
    size_t capacity{16192};
    // Watch out for UnderFlows!!
    size_t _front;
    size_t _back;
    vector<T> q;
    public:
        Deque():_front{capacity + 1},_back{capacity+1},q(capacity){};
        void resize(){
            size_t newCapacity = capacity * 2;
            vector<T> newQ(newCapacity);
            size_t iter = 0;

            while(_front != _back){
                newQ[iter++] = front();
                _front = (_front + 1) % capacity;
            }
            // _front == _back
            newQ[iter] = front();

            _front = 0;
            _back = iter;
            capacity = newCapacity;
            q = newQ;
        }

        void insertFront(T newElement){
            // uninitialized
            if(_front > capacity){
                q[0] = newElement;
                _front = 0;
                _back = 0; 
                return;
            }
            // no space left!
            if( (_front == 0 && _back == capacity - 1) || (_back + 1 == _front) ){
                resize();
            }
            // underFlow Control
            if(_front == 0){
                q[capacity - 1] = newElement;
                _front = capacity - 1;
                return;
            }
            q[_front - 1] = newElement;
            _front--;
        }
        void insertBack(T newElement){
            // uninitialized
            if(_front > capacity){
                q[0] = newElement;
                _front = 0;
                _back = 0; 
                return;
            }
            // no space Left
            if((_back + 1) % capacity == _front){
                resize();
            }
            q[(_back + 1) % capacity] = newElement;
            _back = (_back + 1) % capacity;
        }
        T popFront(){
            T frontElement = front();
            _front = _front == _back ? // Only a single element
             capacity + 1 : // Uninitialized.
             (_front + 1) % capacity;
            return frontElement;
        }
        T popBack(){
            T backElement = back();
            if(_front == _back){ // Only a single element.
                _front = capacity + 1; // Return to uninitialized State.
            }
            _back = _back == 0 ?  capacity - 1 : _back - 1; // Handle Underflow.
            return backElement;
        }
        void clear(){
            _front = capacity + 1;
            _back = capacity + 1;
        }
        T front(){
            assert(!isEmpty());
            return q[_front];
        }
        T back(){
            assert(!isEmpty());
            return q[_back];
        }
        bool isEmpty(){
            return _front> capacity;
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
