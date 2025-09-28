class Solution {
public:
int solve(int idx,int n,int d,vector<int>& jd, vector<vector<int>> &dp){
    if(d==1){
        int mxEle=jd[idx];
       for(int i=idx;i<n;i++){
       mxEle=max(mxEle,jd[i]);
    
       } 
       return mxEle;
    }
    if(d==0 || idx==n){
        return 0;
    }
    if(dp[idx][d]!=-1){
        return dp[idx][d];
    }
    int mxEle=jd[idx];
    int ans=INT_MAX;
    for(int i=idx;i<=(n-d);i++){
        mxEle=max(jd[i],mxEle);
        ans=min(ans,solve(i+1,n,d-1,jd,dp)+mxEle);
    }
    return dp[idx][d]=ans;
}
    int minDifficulty(vector<int>& jD, int d) {
        int n=jD.size();
        vector<vector<int>> dp(n+1,vector<int> (d+1,-1)); 
        if(n<d){
            return-1;
        }
        return solve(0,n,d,jD,dp);
    }
};