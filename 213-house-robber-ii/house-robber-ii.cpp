class Solution {
public:
    int solve(int st,int end,vector<int>& nums){
        int prev=0,prevPrev=0;
        for(int i=st;i<=end;i++){
            int skip=prev;
            int take=prevPrev+nums[i];
            int ans=max(skip,take);
            prevPrev=prev;
            prev=ans;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==1) return max(nums[0],nums[1]);

        int firstTaken=solve(0,n-2,nums);
        int firstNot=solve(1,n-1,nums);
        return max(firstTaken,firstNot);
    }
};