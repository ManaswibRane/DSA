class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int maxsum=nums[0];
        int minsum=nums[0];
        int currsummax=nums[0];
         int currsummin=nums[0];
        for(int i=1;i<nums.size();i++){
           currsummax=max(nums[i],currsummax+nums[i]);
           maxsum=max(currsummax,maxsum);
              currsummin=min(nums[i],currsummin+nums[i]);
           minsum=min(currsummin,minsum);
        }
      
      return max(abs(maxsum),abs(minsum));
     
    }

};