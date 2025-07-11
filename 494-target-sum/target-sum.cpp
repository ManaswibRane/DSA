class Solution {
public:
int ans=0;
    void solve(vector<int>& nums, int target,int n,int sum){
        if(n<0){
            if(target==sum) ans++;
            return;
        }
        solve(nums,target,n-1,sum-nums[n]);
        solve(nums,target,n-1,sum+nums[n]);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size()-1;
        solve(nums,target,n,0);
        return ans;
    }
};