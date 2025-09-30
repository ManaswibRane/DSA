class Solution {
public:
int solve(vector<int>& nums,int i,int j,vector< vector<int>> &dp){
       if((i+1)==j){
        return 0;
       }
      if(dp[i][j]!=-1){
        return dp[i][j];
      }
       int ans=INT_MAX;
       int prod=nums[i]*nums[j];
       for(int idx=(i+1);idx<j;idx++){
           int possible=prod*nums[idx]+solve(nums,i,idx,dp)+solve(nums,idx,j,dp);
           ans=min(possible,ans);
       }
       return dp[i][j]=ans;
}
    int minScoreTriangulation(vector<int>& nums) {
         int n=nums.size();
        vector< vector<int>> dp(n+1,vector<int> (n+1,-1));
          return solve(nums,0,n-1,dp);
    
    }
};