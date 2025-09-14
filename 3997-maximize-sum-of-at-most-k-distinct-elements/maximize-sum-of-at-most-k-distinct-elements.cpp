class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
          sort(nums.begin(),nums.end(),greater<int>());
          vector<int> ans;
          ans.push_back(nums[0]);
          k--;
          for(int i=1;i<nums.size() && k>0;i++){
                  if(nums[i]!=nums[i-1]){
                    ans.push_back(nums[i]);
                    k--;
                  }
          }
          return ans;
    }
};