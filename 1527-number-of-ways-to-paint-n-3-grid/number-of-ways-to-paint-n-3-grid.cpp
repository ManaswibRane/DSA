class Solution {
public:
typedef long long ll;
    int numOfWays(int n) {
        ll abc=6,aba=6,mod=1e9+7;
        for(ll i=1;i<n;i++){
            ll nabc=(3*abc+2*aba)%mod;
            ll naba=(2*aba+2*abc)%mod;
            abc=nabc;
            aba=naba;
        }
        return (aba+abc)%mod;
    }
};