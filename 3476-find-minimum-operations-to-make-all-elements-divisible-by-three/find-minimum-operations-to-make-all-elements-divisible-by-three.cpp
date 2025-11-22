class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ct=0;
        for(int num : nums){
            if(num%3!=0) ct++;
        }
        return ct;
    }
};