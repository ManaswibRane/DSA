class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n==0) return 0;
        if(dp[n]!=-1){
            return dp[n];
        }
        int count =INT_MAX;
        for(int i=1;i*i<=n;i++){
           int ct=1+solve(n-i*i,dp);
           count=min(count,ct);

        }
        return dp[n]=count;
    }
    int numSquares(int n) {
        vector<int> dp(10001,-1);
        return solve(n,dp);
    }
};