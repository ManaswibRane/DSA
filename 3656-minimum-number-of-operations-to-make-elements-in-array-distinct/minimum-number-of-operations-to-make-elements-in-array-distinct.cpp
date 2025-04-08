class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> u;
        for(int i=n-1;i>=0;i--){
            if( u.find(nums[i]) == u.end() ){
                    u.insert(nums[i]);
            }
            else{
                int rem=i+1;
                return rem%3==0 ? rem/3:(rem/3)+1;
            }
             
        }
        return 0;
    }
};