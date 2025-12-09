class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int tot=0;
        for(int num : nums){
            tot+=num;
        }
        int curr=0;
        for(int i=0;i<n-1;i++){
            curr+=nums[i];
            tot-=nums[i];
            if( (curr-tot)%2==0) {ans++;cout<<i<<" "<<tot<<" "<<curr<<endl;}
        }
        return ans;
    }
};