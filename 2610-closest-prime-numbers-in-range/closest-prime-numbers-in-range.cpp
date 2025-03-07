class Solution {
public:
    void Prime( vector<bool> &isPrime,int l,int r,int n){
        isPrime[1]=false;
         isPrime[0]=false;
         for(int i=2;i*i<=r;i++){
            if(isPrime[i]==true){
                for(int j=2;j*i<=r;j++){
                   isPrime[j*i]=false;
                }
            }
         }
    }
    vector<int> closestPrimes(int l, int r) {
        vector<int> ans(2,-1);
        int n=r-l+1;
        vector<bool> isPrime(r+1,true);
        Prime(isPrime,l,r,n);
        int mindiff=INT_MAX;
        vector<int> allPrimes;
        for(int i=l;i<=r;i++){
            if(isPrime[i]){
                 allPrimes.push_back(i);
            }
        }
        for(int i=1;i<allPrimes.size();i++){
             if( (allPrimes[i]-allPrimes[i-1]) <mindiff ){
                ans={allPrimes[i-1],allPrimes[i]};
                mindiff=allPrimes[i]-allPrimes[i-1];
             }
        }
        return ans;
    }
};