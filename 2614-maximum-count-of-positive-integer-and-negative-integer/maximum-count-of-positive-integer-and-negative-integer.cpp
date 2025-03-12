class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int ect=0,oct=0;
        for(int i=0;i<n;i++){
              if(nums[i]>0) ect++;
               if(nums[i]<0) oct++;
        }
        return max(ect,oct);
    }
};