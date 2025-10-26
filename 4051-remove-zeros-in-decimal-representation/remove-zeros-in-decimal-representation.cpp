class Solution {
public:
typedef long long ll;
    long long removeZeros(long long n) {
        ll x=1;
        ll ans=0;
          while(n>0){
              int k=n%10;
              if(k!=0){
                  ans+=k*x;
                  x*=10;
              }
              n/=10;
          }
          return ans;
    }
};