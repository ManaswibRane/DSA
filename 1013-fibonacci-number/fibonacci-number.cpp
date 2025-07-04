class Solution {
public:
vector<int> dp;
    // int solve(int n){
    //     if(n==0 || n==1) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=solve(n-1)+solve(n-2);
    // }
    int fib(int n) {
        dp.resize(n+1,-1);
        if(n==0 || n==1) return n;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
       return dp[n];

    }
};