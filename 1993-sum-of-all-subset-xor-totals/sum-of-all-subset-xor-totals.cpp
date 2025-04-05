class Solution {
public:
   void solve(vector<int>& nums,vector<vector<int>> &res,int i,int n,vector<int> &tar){
        if(i>=n){
            res.push_back(tar);
            return;
        }
        tar.push_back(nums[i]);
         solve(nums,res,i+1,n,tar);
         tar.pop_back();
         solve(nums,res,i+1,n,tar);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> tar;
        solve(nums,res,0,n,tar);
        return res;
    }
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        vector<vector<int>> subset=subsets(nums);
        for(int i=0;i<subset.size();i++){
            int x=0;
            for(int j=0;j< subset[i].size();j++){
              x= x ^ subset[i][j];
            }
            ans+=x;
        }
        return ans;
       
    }
};