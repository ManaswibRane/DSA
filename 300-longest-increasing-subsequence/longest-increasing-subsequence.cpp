class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n,1);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
         
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    t[i]=max(t[j]+1,t[i]);
                
                }
            }
            cout<<t[i]<<endl;
              ans=max(ans,t[i]);
        }
        return ans;
    }
};