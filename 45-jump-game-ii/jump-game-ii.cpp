class Solution {
public:
int solve(vector<int>& nums,int n,int i, vector<int> &dp){
   if(i==n-1){
    return 0;
   }
   if(dp[i]!=-1){
    return dp[i];
   }
   int ans=INT_MAX;
   for(int idx=1;idx<=nums[i] && i+idx<n;idx++){
    int poss=solve(nums,n,i+idx,dp);
    if(poss!=INT_MAX) ans=min(ans,1+poss);
   }
   return dp[i]=ans;
   
}
    int jump(vector<int>& nums) {

        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,n,0,dp);
    }
};