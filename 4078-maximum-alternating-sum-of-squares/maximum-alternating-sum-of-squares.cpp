class Solution {
public:
typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
             if(nums[i]<0){
                nums[i]=-nums[i];
          }
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        ll ans=0;
        int i=0,j=n-1;
        while(i<=j){
           if(i!=j){
            ans-=(nums[i]*nums[i]);
           }
           ans+=nums[j]*nums[j];
           j--;
           i++;
        }
        return ans;
    }
};