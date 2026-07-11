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
//ll sayilar2[8]{4,8,8,8,9,11,13};
ll upper_bound_custom(ll* array, ll n, ll element){
    if(n == 0){
        return 0;
    }
    // array[l] <= element
    ll l = 0;
    if(array[0] > element){
        return 0;
    }
    // array[r] > element
    ll r = n - 1;
    if(array[r] <= element){
        return n;
    }
    while(l < r - 1){
        ll mid = l + (r-l)/2;
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
//ll sayilar2[8]{4,8,8,8,9,11,13};
ll lower_bound_custom(ll* array, ll n, ll element){
    if(n == 0){
        return 0;
    }
    // array[l] < element
    ll l = 0;
    if(array[0] >= element){
        return 0;
    }
    // array[r] >= element
    ll r = n - 1;
    if(array[r] < element){
        return n;
    }
    while(l < r - 1){
        ll mid = l + (r-l)/2;
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
    // initialize
    if(n == 0){
        return -1;
    }
    // l is accepted
    ll l = 0;
    if(array[0] >= element){
        return -1;
    }
    // r is rejected.
    ll r = n - 1;
    if(array[r] < element){
        return r;
    }

    // l is accepted, l+1 is not
    while(l < r - 1){
        ll mid = l + (r - l) / 2;
        // mid is accepted.
        if(array[mid] < element){
            l = mid;
        }
        // equality is rejected.
        else{
            r = mid;
        }
    }
    return l;
}

int main(){
    ll sayilar[5]{4,8,9,11,13};
    //testcases
    check(last_less(sayilar,5,3), -1, "last lessnot found, the lowest element is >= search");
    // 2 -> largest element < aranan
    check(last_less(sayilar,5,33), 4, "last lesslargest element < aranan");
    // the first element
    check(last_less(sayilar,5,5), 0, "last lessthe first element");
    // 
    check(last_less(sayilar,5,10), 2, "last lesssomewhere in the middle");
    // last element
    check(last_less(sayilar,5,13), 3, "last lesslast element");
    // first element
    check(last_less(sayilar,5,4), -1, "last lessnot found, exacct hit on lowest");
    // n = 0
    check(last_less(sayilar,0,4), 0, "last lessn = 0");
    // n = 1
    check(last_less(sayilar,1,8), 0, " last less n = 1, hit");
    // n = 1
    check(last_less(sayilar,1,2), -1, "last lessn = 1, miss");

    ll sayilar2[7]{4,8,8,8,9,11,13};
    //testcases
    // 1 -> not found, the lowest element is >= search
    check(lower_bound_custom(sayilar2,7,3), 0, "2not found, the lowest element is >= search");
    // 2 -> largest element < aranan
    check(lower_bound_custom(sayilar2,7,33), 7, "2largest element < aranan");
    // the first element
    check(lower_bound_custom(sayilar2,7,8), 1, "2the first element");
    // 
    check(lower_bound_custom(sayilar2,7,9), 4, "2somewhere in the middle");
    // hits the last element
    check(lower_bound_custom(sayilar2,7,13), 6, "last element, exact hit");
    // first element
    check(lower_bound_custom(sayilar2,5,4), 0, "first element,exact hit");
    // n = 0
    check(lower_bound_custom(sayilar2,0,4), 0, " n = 0");
    // n = 1
    check(lower_bound_custom(sayilar2,1,1), 0, "n= 1, hit");
    // n = 1
    check(lower_bound_custom(sayilar2,1,4), 0, "n= 1, exact hit ");
    // n = 1
    check(lower_bound_custom(sayilar2,1,8), 1, "n= 1,miss ");

    //testcases
    // 1 -> not found, the lowest element is >= search
    check(upper_bound_custom(sayilar2,7,3), 0, "2not found, the lowest element is >= search");
    // 2 -> largest element < aranan
    check(upper_bound_custom(sayilar2,7,33), 7, "2largest element < aranan");
    // the first element
    check(upper_bound_custom(sayilar2,7,8), 4, "2the first element");
    // 
    check(upper_bound_custom(sayilar2,7,9), 5, "2somewhere in the middle");
    // hits the last element
    check(upper_bound_custom(sayilar2,7,13), 7, "last element, exact hit");
    // first element
    check(upper_bound_custom(sayilar2,5,4), 1, "first element,exact hit");
    // n = 0
    check(upper_bound_custom(sayilar2,0,4), 0, " n = 0");
    // n = 1
    check(upper_bound_custom(sayilar2,1,1), 0, "n= 1, hit");
    // n = 1
    check(upper_bound_custom(sayilar2,1,4), 1, "n= 1, exact hit");
    // n = 1
    check(upper_bound_custom(sayilar2,1,8), 1, "n= 1,miss");
}
