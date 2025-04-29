class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0,n=nums.size();
        for(int i=0;i<n;i++){
            x^=nums[i];

        }
        int diff=k^x;
        int ans=__builtin_popcount(diff);
        return ans;
    }
};