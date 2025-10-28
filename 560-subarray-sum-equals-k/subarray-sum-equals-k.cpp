class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int pre=0;
        int ans=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++)
        {
               pre+=nums[i];
               if(mp.find(pre-k)!=mp.end()){
                       ans+=mp[pre-k];
               }
               mp[pre]++;
        }
        return ans;
    }
};