class Solution {
public:
   
    long long mod=pow(10,9)+7;
long long Longpow(long long base, long long exp) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
    int countGoodNumbers(long long n) {
      int ans;
      long long even=(n+1)/2;
      long long odd=n/2;
   long long prod=(Longpow(5,even)*Longpow(4,odd))%mod;
   ans=int(prod);
        return ans;
    }
};