class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> u;

        int i=0,j=0;
        while(j<n){
             if(abs(i-j)>k){
                   u[nums[i]]--;
                   if(u[nums[i]]==0) u.erase(nums[i])  ;
                   i++;
            }
            if(u.find(nums[j])==u.end()){
                   u[nums[j]]++;

            }else{
                return true;
            }
           
        j++;
        }
        return false;
    }
};