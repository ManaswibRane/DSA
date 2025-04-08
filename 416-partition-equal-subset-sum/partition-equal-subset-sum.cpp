class Solution {
public:

    bool solve(vector<int>& nums,int n,int sum,int idx,int x, vector<vector<int>>& t){
        if(idx>=n){
             if(sum==2*x){
                return true;
             }
             return false;
        }
        if(sum==2*x){
           return true;
        }
        if(x>sum/2){
            return false;
        }
        if(t[idx][x]!=-1){
            return t[idx][x];
        }
       bool take= solve(nums,n,sum,idx+1,x+nums[idx],t);

       bool not_Take=solve(nums,n,sum,idx+1,x,t);
      return t[idx][x]=take | not_Take;
    }
    bool canPartition(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
     
       for(int i=0;i<n;i++){
             sum+=nums[i];
       }
       if(sum%2!=0) return false;
        vector<vector<int>> t(n+1,vector<int>((sum/2)+2,-1)); 
      
       return solve(nums,n,sum,0,0,t);
    }

};