class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n=nums.size();
        int ct=n-1;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                ans[ct--]=1;
            }
        }
        return ans;
    }
};