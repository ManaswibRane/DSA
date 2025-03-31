class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
          int n=nums.size();
            sort(nums.begin(),nums.end());
           vector<int> sum;
           int ans=0;
           for(int i=0;i<n-1;i=i+2){

               ans+=min(nums[i],nums[i+1]);
            
            
           }
    
        return ans;
     }
};