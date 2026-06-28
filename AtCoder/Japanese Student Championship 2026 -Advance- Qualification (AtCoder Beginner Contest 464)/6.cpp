#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 998244353;
const ll MAX_N = 42;

constexpr int carmichael_constexpr(int n){
  if(n==998244353)return 998244352;
  if(n==1000000007)return 1000000006;
  if(n<=1)return n;
  int res=1;
  int t=0;
  while(n%2==0){
    n/=2;
    t++;
  }
  if(t==2)res=2;
  else if(t>=3)res=1<<(t-2);
  for(int i=3;i*i<=n;i++)if(n%i==0){
    int c=0;
    while(n%i==0){
      n/=i;
      c++;
    }
    int prod=i-1;
    for(int j=0;j<c-1;j++)prod*=i;
    res=std::lcm(res,prod);
  }
  if(n!=1)res=std::lcm(res,n-1);
  return res;
}
template<int m>
struct mod_int{
private:
  static constexpr unsigned int umod=static_cast<unsigned int>(m);
  static constexpr unsigned int car=carmichael_constexpr(m);
  using uint=unsigned int;
  using mint=mod_int;
  uint v;
  static_assert(m<uint(1)<<31);
  mint sqrt_impl()const{
    if(this->val()<=1)return *this;
    // evaluated at compile time, depending on m
    // ToDo
    // understand and implement
    if constexpr(m%8==1){
      mint b=2;
      while(b.pow((m-1)/2).val()==1)b++;
      int m2=m-1,e=0;
      while(m2%2==0)m2>>=1,e++;
      mint x=this->pow((m2-1)/2);
      mint y=(*this)*x*x;
      x*=*this;
      mint z=b.pow(m2);
      while(y.val()!=1){
        int j=0;
        mint t=y;
        while(t.val()!=1)t*=t,j++;
        z=z.pow(1<<(e-j-1));
        x*=z;
        z*=z;
        y*=z;e=j;
      }
      return x;
    }
    else if constexpr(m%8==5){
      mint ret=this->pow((m+3)/8);
      if((ret*ret).val()==this->val())return ret;
      else return ret*mint::raw(2).pow((m-1)/4);
    }
    else{
      return this->pow((m+1)/4);
    }
  }
public:
  using value_type=uint;
  mod_int():v(0){}
  template<typename T,std::enable_if_t<std::is_signed_v<T>,std::nullptr_t> =nullptr>
  mod_int(T a){
    a%=m;
    if(a<0)v=a+umod;
    else v=a;
  }
  template<typename T,std::enable_if_t<std::is_unsigned_v<T>,std::nullptr_t> =nullptr>
  mod_int(T a):v(a%umod){}
  static constexpr mint raw(int a){
    mint ret;
    ret.v=a;
    return ret;
  }
  inline uint val()const{return this->v;}
  static constexpr int mod(){return m;}
  inline mint &operator+=(const mint &b){
    this->v+=b.v;
    if(this->v>=umod)this->v-=umod;
    return *this;
  }
  inline mint &operator-=(const mint &b){
    this->v-=b.v;
    if(this->v>=umod)this->v+=umod;
    return *this;
  }
  inline mint &operator*=(const mint &b){
    this->v=((unsigned long long)this->v*b.v)%umod;
    return *this;
  }
  inline mint &operator/=(const mint &b){
    *this*=b.inv();
    return *this;
  }
  inline mint operator+()const{return *this;}
  inline mint operator-()const{return mint()-*this;}
  friend inline mint operator+(const mint &a,const mint &b){return mint(a)+=b;}
  friend inline mint operator-(const mint &a,const mint &b){return mint(a)-=b;}
  friend inline mint operator*(const mint &a,const mint &b){return mint(a)*=b;}
  friend inline mint operator/(const mint &a,const mint &b){return mint(a)/=b;}
  friend inline bool operator==(const mint &a,const mint &b){return a.val()==b.val();}
  friend inline bool operator!=(const mint &a,const mint &b){return !(a==b);}
  friend inline bool operator<(const mint &a,const mint &b){return a.val()<b.val();}
  friend inline bool operator>(const mint &a,const mint &b){return a.val()>b.val();}
  friend inline bool operator<=(const mint &a,const mint &b){return a.val()<=b.val();}
  friend inline bool operator>=(const mint &a,const mint &b){return a.val()>=b.val();}
  inline mint operator++(int){
    mint ret=*this;
    *this+=mint::raw(1);
    return ret;
  }
  inline mint operator--(int){
    mint ret=*this;
    *this-=mint::raw(1);
    return ret;
  }
  mint pow(long long n)const{
    mint ret=mint::raw(1),a(*this);
    while(n){
      if(n&1)ret*=a;
      a*=a;
      n>>=1;
    }
    return ret;
  }
  inline mint inv()const{
    assert(this->v!=0);
    return pow(car-1);
  }
  std::optional<mint>sqrt()const{
    if(this->val()<=1||this->pow((m-1)/2)==1)return std::make_optional(this->sqrt_impl());
    else return std::nullopt;
  }
  static constexpr unsigned int order(){return car;}
  friend std::istream &operator>>(std::istream &is,mint &b){
    long long a;
    is>>a;
    b=mint(a);
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os,const mint &b){
    os<<b.val();
    return os;
  }
};
using mint = mod_int<MOD>;

mint fact[MAX_N];
mint inv_fact[MAX_N];
void precompute_factorials() {
    fact[0] = 1;
    for (ll i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i - 1] * mint(i));
    }
    inv_fact[MAX_N-1] = fact[MAX_N-1].inv();  // one modular inverse
    for (ll i = MAX_N-2; i >= 0; i--)
        inv_fact[i] = inv_fact[i+1] * mint(i+1);  // work backwards
}

// sum -> [bitmask...]
map<ll,set<ll>> knapsack;
ll a[MAX_N + 1];
void solve(){
    ll n,x;
    cin >> n >> x;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a + n);
    ll leftSideEnd = n/2;
    ll rightSideStart = n-leftSideEnd;

    ll sumL = 0,sumR = 0;
    for(int i = 0; i < leftSideEnd; i++){
      sumL += a[i];
    }
    for(int i = leftSideEnd; i < n; i++){
      sumR += a[i];
    }
        
    vector<vector<ll>> leftBySizeK(leftSideEnd + 1);
    vector<vector<ll>> rightBySizeK(rightSideStart + 1);

    for(ll mask = 0; mask < 1 << leftSideEnd; mask++){
      ll sum = 0;
      for(int j = 0; j < leftSideEnd; j++){
        if(mask>>j & 1) sum += a[j];}
      
      leftBySizeK[__builtin_popcountll(mask)].push_back(sum);
    }
    for(ll mask = 0; mask < 1 << rightSideStart; mask++){
      ll sum = 0;
      for(int j = 0; j < rightSideStart; j++){
        if (mask>>j&1) sum += a[leftSideEnd + j];}
      
      rightBySizeK[__builtin_popcountll(mask)].push_back(sum);
    }
    for (auto& v : leftBySizeK) sort(v.begin(), v.end());
    for (auto& v : rightBySizeK) sort(v.begin(), v.end());

    mint total = 0;

    // first element is from left side
    for(ll mask = 0; mask < 1 << leftSideEnd; mask++){
      ll sum = 0;
      for(int j = 0; j < leftSideEnd; j++){
        if(mask & (1 << j)){ sum += a[j];}
      }
      int kL = __builtin_popcountll(mask);
      if(sum > x || sumL - sum == 0){
        continue;
      }
      mint F = 0;
      for(int k = 0; k < rightBySizeK.size(); k++){
        auto& v = rightBySizeK[k];  
        int count = lower_bound(v.begin(),v.end(), x- sum) - v.begin();
        F += mint(count) * fact[k + kL] * fact[n - k - kL - 1];
      }
      total += mint(sumL - sum) * F;
    }
    // first element is from right side
    for(ll mask = 0; mask < 1 << rightSideStart; mask++){
      ll sum = 0;
      for(int j = 0; j < rightSideStart; j++){
        if(mask & (1 << j)){ sum += a[leftSideEnd + j];}
      }
      int kR = __builtin_popcountll(mask);
      if(sum > x || sumR - sum == 0){
        continue;
      }
      mint F = 0;
      for(int k = 0; k < leftBySizeK.size(); k++){
        auto& v = leftBySizeK[k];  
        int count = lower_bound(v.begin(),v.end(), x- sum) - v.begin();
        F += mint(count) * fact[k + kR] * fact[n - k - kR - 1];
      }
      total += mint(sumR - sum) * F;
    }
    cout << total * fact[n].inv() << endl;
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute_factorials();
    solve();
}

