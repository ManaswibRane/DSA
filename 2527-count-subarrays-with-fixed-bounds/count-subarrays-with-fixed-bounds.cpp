class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size();
        int bad=-1,currmin=-1,currmax=-1;
       for(int i=0;i<n;i++){
        if(nums[i]<minK || nums[i]>maxK) bad=i;
        if(nums[i]==minK) currmin=i;
        if(nums[i]==maxK) currmax=i;
      int smaller=min(currmin,currmax);
      int temp=smaller - bad;
      ans+=temp<0? 0:temp;
       }
        return ans;
    }
};