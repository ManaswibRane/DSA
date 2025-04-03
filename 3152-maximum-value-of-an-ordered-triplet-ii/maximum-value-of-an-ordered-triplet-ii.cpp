class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size(),idxm=1,idx=0;
        if(n<3) return 0;
        long long maxdiff=0,maxi=0;
        long long res=0;
        for(int k=0;k<n;k++){
           res=max(res,(long long)(maxdiff)*nums[k]);
           maxdiff=max(maxi-nums[k],maxdiff);
           maxi=max(maxi,(long long)nums[k]);
        }
        
           return res;
    }
};