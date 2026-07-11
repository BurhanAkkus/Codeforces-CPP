#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>

void check(int got, int expected, const std::string& name) {
    if (got != expected) {
        std::cerr << "FAIL " << name << ": got " << got
                  << ", expected " << expected << "\n";
        assert(false);
    }
}


// returns the first element i such that array[i] > element
ll upper_bound_custom(ll* array, ll n, ll element){
    if(n == 0){
        return 0;
    }
    ll l = 0;
    // array[l] <= element
    if(array[l] > element){
        return l;
    }
    // array[r] > element
    ll r = n-1;
    if(array[r] <= element){
        return n;
    }
    while(l < r-1){
        ll mid = l + (r - l) / 2;
        if(array[mid] <= element){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}

// returns the first element i such that array[i] >= element
ll lower_bound_custom(ll* array, ll n, ll element){
    if(n == 0){
        return 0;
    }
    ll l = 0;
    // array[l] < element
    if(array[l] >= element){
        return l;
    }
    // array[r] >= element
    ll r = n-1;
    if(array[r] < element){
        return n;
    }
    while(l < r-1){
        ll mid = l + (r - l) / 2;
        if(array[mid] < element){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}

ll last_less(ll* array, ll n,ll element){
    return lower_bound_custom(array,n,element) - 1;
}

int main(){
    ll sayilar[5]{4,8,9,11,13};
    //testcases
    check(last_less(sayilar,5,3), -1, "last less not found, the lowest element is >= search");
    // 2 -> largest element < aranan
    check(last_less(sayilar,5,33), 4, "last less largest element < aranan");
    // the first element
    check(last_less(sayilar,5,5), 0, "last less the first element");
    // 
    check(last_less(sayilar,5,10), 2, "last less somewhere in the middle");
    // last element
    check(last_less(sayilar,5,13), 3, "last less last element");
    // first element
    check(last_less(sayilar,5,4), -1, "last less not found, exacct hit on lowest");
    // n = 0
    check(last_less(sayilar,0,4), -1, "last less n = 0");
    // n = 1
    check(last_less(sayilar,1,8), 0, " last less n = 1, hit");
    // n = 1
    check(last_less(sayilar,1,2), -1, "last less n = 1, miss");

    ll sayilar2[7]{4,8,8,8,9,11,13};
    //testcases
    // 1 -> not found, the lowest element is >= search
    check(lower_bound_custom(sayilar2,7,3), 0, "lower_bound_custom not found, the lowest element is >= search");
    // 2 -> largest element < aranan
    check(lower_bound_custom(sayilar2,7,33), 7, "lower_bound_custom largest element < aranan");
    // the first element
    check(lower_bound_custom(sayilar2,7,8), 1, "lower_bound_custom the first element");
    // 
    check(lower_bound_custom(sayilar2,7,9), 4, "lower_bound_custom somewhere in the middle");
    // hits the last element
    check(lower_bound_custom(sayilar2,7,13), 6, "lower_bound_custom last element, exact hit");
    // first element
    check(lower_bound_custom(sayilar2,5,4), 0, "lower_bound_custom first element,exact hit");
    // n = 0
    check(lower_bound_custom(sayilar2,0,4), 0, "lower_bound_custom n = 0");
    // n = 1
    check(lower_bound_custom(sayilar2,1,1), 0, "lower_bound_custom n= 1, hit");
    // n = 1
    check(lower_bound_custom(sayilar2,1,4), 0, "lower_bound_custom n= 1, exact hit ");
    // n = 1
    check(lower_bound_custom(sayilar2,1,8), 1, "lower_bound_custom n= 1,miss ");

    //testcases
    // 1 -> not found, the lowest element is >= search
    check(upper_bound_custom(sayilar2,7,3), 0, "upper_bound_custom not found, the lowest element is >= search");
    // 2 -> largest element < aranan
    check(upper_bound_custom(sayilar2,7,33), 7, "upper_bound_custom largest element < aranan");
    // the first element
    check(upper_bound_custom(sayilar2,7,8), 4, "upper_bound_custom the first element");
    // 
    check(upper_bound_custom(sayilar2,7,9), 5, "upper_bound_custom somewhere in the middle");
    // hits the last element
    check(upper_bound_custom(sayilar2,7,13), 7, "upper_bound_custom last element, exact hit");
    // first element
    check(upper_bound_custom(sayilar2,5,4), 1, "upper_bound_custom first element,exact hit");
    // n = 0
    check(upper_bound_custom(sayilar2,0,4), 0, "upper_bound_custom n = 0");
    // n = 1
    check(upper_bound_custom(sayilar2,1,1), 0, "upper_bound_custom n= 1, hit");
    // n = 1
    check(upper_bound_custom(sayilar2,1,4), 1, "upper_bound_custom n= 1, exact hit");
    // n = 1
    check(upper_bound_custom(sayilar2,1,8), 1, "upper_bound_custom n= 1,miss");

    mt19937_64 rng(12345);
    for (int t = 0; t < 100000; ++t) {
        ll n = rng() % 6;                       // include 0 and 1
        vector<ll> a(n);
        for (auto& v : a) v = rng() % 8;        // tiny range → forced duplicates
        sort(a.begin(), a.end());
        ll x = rng() % 10;                      // include values below and above
        assert(lower_bound_custom(a.data(), n, x) ==
            lower_bound(a.begin(), a.end(), x) - a.begin());
        assert(upper_bound_custom(a.data(), n, x) ==
            upper_bound(a.begin(), a.end(), x) - a.begin());
        assert(last_less(a.data(), n, x) ==
            *lower_bound(a.data(), a.data() + n, x) - 1);
    }
}
