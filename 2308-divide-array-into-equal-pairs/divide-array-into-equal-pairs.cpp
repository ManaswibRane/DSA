class Solution {
public:
    bool divideArray(vector<int>& nums) {
       if(nums.size()%2!=0) return false;
        int n=nums.size()/2;
        int count=0;
        unordered_map<int,int> ct;
        for(int i=0;i<nums.size();i++){
             ct[nums[i]]++;
             }     
        for(auto it:ct){
            if(it.second %2!=0) return false;
        }              
        return true;
    }
};