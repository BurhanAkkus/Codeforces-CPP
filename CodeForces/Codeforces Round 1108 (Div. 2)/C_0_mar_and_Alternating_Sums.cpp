#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

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

using mint =mod_int<1000000007>;
array<ll,MAX_N> a;
vector<pair<ll,ll>> counts;

mint pow2Lookup[MAX_N];

void preComputePow2Lookup(){
    pow2Lookup[0] = mint(1);
    rep(i,1,MAX_N,1){
        pow2Lookup[i] = pow2Lookup[i-1] * 2;
    }
}

mint dp[MAX_N][2];

void solve(){
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> a[i];
    }
    counts.clear();
    counts.push_back({a[n-1],1});
    rep(i,1,n,1){
        if(counts.back().first == a[n-1-i]){
            counts.back().second++;
        }
        else{
            counts.push_back({a[n-1-i],1});
        }
    }
    dp[0][0] = pow2Lookup[counts[0].second - 1];
    dp[0][1] = 0;
    rep(i,1,counts.size() -1 ,1){
        auto[sayi,count] = counts[i];
        // add even to sum0s.
        dp[i][0] = dp[i-1][0] * pow2Lookup[count - 1];
        // add even to sum1s.
        dp[i][1] = dp[i-1][1] * pow2Lookup[count - 1];
        // 
        if(counts[i-1].first == sayi + 1){
            dp[i][1] += ( i > 1 ? dp[i-2][0] : 1) * pow2Lookup[counts[i-1].second - 1] * pow2Lookup[count - 1];
        }
    }
    mint ans = 0;
    if(counts.size() > 1){
        auto [lastSayi,lastSayiCount] = counts[counts.size() -1];
        if(lastSayi == -1){
            // sum 0 + sum 0
            ans += dp[counts.size() - 2][0] * pow2Lookup[lastSayiCount -1];
            // sum 1 + sum -1
            ans += dp[counts.size() - 2][1] * pow2Lookup[lastSayiCount -1];
        }
        else{
            ans += dp[counts.size() - 2][0] * pow2Lookup[lastSayiCount -1];
        }
    }
    else{
        ans = dp[0][0];
    }
    cout << ans << "\n";
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    preComputePow2Lookup();
    cin >> t;
    while(t--){
        solve();
    }
}