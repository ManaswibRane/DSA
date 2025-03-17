class Solution {
public:
    bool divideArray(vector<int>& nums) {
       if(nums.size()%2!=0) return false;
        
        unordered_set<int> ct;
        for(int i=0;i<nums.size();i++){
             if(ct.find(nums[i])!=ct.end()){
                ct.erase(nums[i]);

             }
             else{
                ct.insert(nums[i]);
             }
             }     
                  
        return ct.empty();
    }
};