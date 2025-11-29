class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int num : nums){
            sum+=num;
            sum=sum%k;
        }
        return (sum%k);
    }
};