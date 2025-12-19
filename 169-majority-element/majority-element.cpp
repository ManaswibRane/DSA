class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ct=0,ele=nums[0];
        for(int i=0;i<n;i++){
           if(ele==nums[i]) ct++;
           else ct--;
           if(ct==0) {ele=nums[i];ct++;}
        }
        return ele;

    }
};