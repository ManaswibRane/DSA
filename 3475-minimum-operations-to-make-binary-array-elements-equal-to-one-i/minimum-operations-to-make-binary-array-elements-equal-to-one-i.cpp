class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),ans=0;
        int i=0;
        while(i<n-2){
            if(nums[i]==0){
                ans++;
                int temp=i;
                while(temp<i+3){
                    nums[temp]=nums[temp]==0? nums[temp]=1: nums[temp]=0;
                    temp++;
                }

            }
            i++;
        }
    for(int i=n-2;i<n;i++){
        if(nums[i]==0) return -1;
    }
        return ans;
    }
};