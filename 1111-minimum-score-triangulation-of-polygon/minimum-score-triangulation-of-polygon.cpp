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
int solveMem(vector<int>& nums,vector< vector<int>> &dp){
     
       int n=nums.size();
       for(int i=n-1;i>=0;i--){
          for(int j=i+2;j<n;j++){
           int ans=INT_MAX;
           int prod=nums[i]*nums[j];
           for(int idx=(i+1);idx<j;idx++){
             int possible=prod*nums[idx]+dp[i][idx]+dp[idx][j];
             ans=min(possible,ans);
             }
       dp[i][j]=ans;
        }
       }
       return dp[0][n-1];
}
    int minScoreTriangulation(vector<int>& nums) {
         int n=nums.size();
        vector< vector<int>> dp(n+1,vector<int> (n+1,0));
          return solveMem(nums,dp);
    
    }
};