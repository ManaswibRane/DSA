class Solution {
public:

    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int r=0;
        for(int num:nums){
            r|=num; 
        }
        
      return r << (n-1);
       
    }
};