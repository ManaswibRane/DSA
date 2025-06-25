class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prevSum=INT_MIN,i=0,n=nums.size();
        int ans=INT_MIN;
        while(i<n){
           
            if(prevSum<=0){
                prevSum=nums[i];
            }
            else{
                prevSum+=nums[i];
          
            }
                  i++;
                   ans=max(ans,prevSum);
        }
        return ans;
    }
};