class Solution {
public:
vector<int> dp;

    int climbStairs(int n) {
        dp.resize(n+1);
        if(n==0 || n==1 || n==2) return n;
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};