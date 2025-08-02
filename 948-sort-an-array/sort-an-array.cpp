class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        vector<int> ans;
        int MX=*max_element(nums.begin(),nums.end());
        int MN=*min_element(nums.begin(),nums.end());
        for(int i=MN;i<=MX;i++){
               while(mp[i]>0){
                ans.push_back(i);
                 mp[i]--;
               }
        }
        return ans;
    }
};