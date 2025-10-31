class Solution {
public:
int solve(string &text1, string& text2,int i,int j, vector<vector<int>>& dp){
      if(i>=text1.length() || j>=text2.length()){
          return 0;
      }
      if(dp[i][j]!=-1){
        return dp[i][j];
      }
      int ans=0;
      int ans1=0,ans2=0,ans3=0;
      if(text1[i]==text2[j]){
        ans1=1+solve(text1,text2,i+1,j+1,dp);


      }
      ans2=solve(text1,text2,i+1,j,dp);
      ans3=solve(text1,text2,i,j+1,dp);
      return dp[i][j]=max({ans1,ans2,ans3});
}
    int longestCommonSubsequence(string text1, string text2) {
        if(text1==text2){
            return text1.length();
        }
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return solve(text1,text2,0,0,dp);
    }
};