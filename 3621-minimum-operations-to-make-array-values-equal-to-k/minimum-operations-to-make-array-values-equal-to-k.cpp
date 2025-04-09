class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        if(nums[0]<k){
            return -1;
        }
        int n=nums.size();
        int ct=0;
        int x=nums[n-1];
        for(int i= n-1;i>=0;i--){
             if(nums[i]!=x){
                ct++;
                x=nums[i];
             }
        }
        if(nums[0]!=k){
            ct++;
        }
        return ct;
    }
};