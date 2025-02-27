class Solution {
public:
   int solve(int i,int j,vector<int>& arr,unordered_map<int,int> &mp,vector<vector<int>> &dp) {
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int x=arr[i]-arr[j];
    if(x<0){
        return 2;
    }
    if(mp.find(x)!=mp.end()){
        int k=mp[x];
        if(k<j) { return dp[i][j]= solve(j,k,arr,mp,dp)+1;}
    }
    return 2;
   }
   int lenLongestFibSubseq(vector<int>& arr) {
    unordered_map<int,int> mp;

    int n=arr.size(),ml=0;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        mp[arr[i]]=i;
    }
    for(int i=n-1;i>=2;i--){
        for(int j=i-1;j>=1;j--){
            ml=max(ml,solve(i,j,arr,mp,dp));
        }
    }
    return ml>2? ml:0;
    }
};