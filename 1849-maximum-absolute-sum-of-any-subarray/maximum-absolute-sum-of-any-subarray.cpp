class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = nums[0];  
        int minsum = nums[0];  
        int currmax = nums[0]; 
        int currmin = nums[0]; 

        
        for (int i = 1; i < nums.size(); i++) {
            currmax = max(nums[i], currmax + nums[i]);
            maxsum = max(maxsum, currmax);

            currmin = min(nums[i], currmin + nums[i]);
            minsum = min(minsum, currmin);
        }

        
        return max(abs(maxsum), abs(minsum));
    }
};
