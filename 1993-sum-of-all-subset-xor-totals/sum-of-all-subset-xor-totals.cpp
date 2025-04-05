class Solution {
public:
   int solve(vector<int>& nums,int i,int n,int  X){
        if(i>=n){
            return X;
        }
        
       int include=solve(nums,i+1,n,X^nums[i]);
    
         int excludes=solve(nums,i+1,n,X);
         return include+excludes;
   }
    int subsets(vector<int> &nums) {
        int n=nums.size();
       return solve(nums,0,n,0);
       
    }
    int subsetXORSum(vector<int>& nums) {
      return subsets(nums) ;
       
    }
};