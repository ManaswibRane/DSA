class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
    
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i!=n-1 && nums[i]==nums[i+1]){
                nums[i]*=2;
                 nums[i+1]=0;
            }
            
        }
        for(int i=0;i<n-1;i++){
            if(!nums[i])
            {
                int x=i+1;
                 while(nums[x]==0 && x<n-1){
                    x++;
                 }
                 nums[i]=nums[x];
                 nums[x]=0;
            }
        
        }
    return nums;
    }
};
