class Solution {
public:
int solve( vector<vector<int>>& dp,int i,int n,int amt,vector<int> &coins){

   if(amt==0){
    return 0;
   }
   if(i>=n){
    return INT_MAX-1;
   }
   if(dp[i][amt]!=-1){
    return dp[i][amt];
   }
   int take=INT_MAX-1,notTake=INT_MAX-1;

    if(coins[i]<=amt){
          take=1+solve(dp,i,n,amt-coins[i],coins);
    }
    notTake=solve(dp,i+1,n,amt,coins);
    // if((take==INT_MAX || take==INT_MAX-1) && (notTake==INT_MAX || notTake==INT_MAX -1)){
    //     return -1;
    // }
    return dp[i][amt]=min(take,notTake);
}
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
         vector<vector<int>> dp(n+1,vector<int> (amt+1,-1));
         int res= solve(dp,0,n,amt,coins);
         return (res >= INT_MAX - 1) ? -1 : res;
    }
};