class Solution {
public:

    bool unique(string s1,string s2){
        vector<int> val(26,0);
        for(char ch: s2){
            if(val[ch-'a']>0) return true;
            val[ch-'a']++;
        }
       for(char ch: s1){
            if(val[ch-'a']>0) return true;
            val[ch-'a']++;
        }
        return false;

    }
    int solve(int idx,int n,vector<string>& arr,string temp ,vector<int> dp){
          if(idx>=n) return temp.length();
          if(dp[idx]!=-1) return dp[idx];
           int take=0,notTake=0;
          if(unique(temp,arr[idx])){
                notTake=solve(idx+1,n,arr,temp,dp);
          }
          else{
            take=solve(idx+1,n,arr,temp+arr[idx],dp);
            notTake=solve(idx+1,n,arr,temp,dp);
          }
          return dp[idx]=max(take,notTake);
    }
    int maxLength(vector<string>& arr) {
          int n=arr.size();
          vector<int> dp(16,-1);
          return solve(0,n,arr,"",dp);
    }
};