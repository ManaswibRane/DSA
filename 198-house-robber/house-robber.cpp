class Solution {
public:
    vector<int> dp;
    int solve(int n,int i,vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+solve(n,i+2,nums);
        int notTake=solve(n,i+1,nums);
        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
         dp.resize(n+1,-1);
        return solve(n,0,nums);
    }
};