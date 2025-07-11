class Solution {
public:
    long long solve(vector<int>& nums,int idx,bool flag,  vector<vector<long long>>& dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        long long Ntake=solve(nums,idx+1,flag,dp);
        int val=nums[idx];
        if(flag!=false){
           val=-val;
        }
        long long take=val+solve(nums,idx+1,!flag,dp);
        return dp[idx][flag]=max(take,Ntake);

    }
    long long maxAlternatingSum(vector<int>& nums) {
            vector<vector<long long>> dp(nums.size()+1,vector<long long> (2,-1));
        return solve(nums,0,0,dp);
    }
};