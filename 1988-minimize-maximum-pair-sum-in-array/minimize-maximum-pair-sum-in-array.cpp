class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> sum;
        for(int i=0;i<n;i++){
            sum.push_back(nums[i]+nums[n-i-1]);
        }
        sort(sum.begin(),sum.end());
        int x=sum.size();
        return sum[x-1];
    }
};