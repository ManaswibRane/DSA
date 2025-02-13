class Solution {
public:
int sumofdigits(int n){
    int ans=0;
    while(n){
       int k=n%10;
       ans+=k;
       n/=10;
    }
    return ans;
    }

    int maximumSum(vector<int>& nums) {
        int n=nums.size(),ans=-1;
       unordered_map<int ,int> mp;//digisum==key  value==number
       for(int i=0;i<n;i++){
          int digitsum=sumofdigits(nums[i]);
          if(mp.count(digitsum)){
            ans=max(ans,nums[i]+mp[digitsum]);
              mp[digitsum]=max(nums[i],mp[digitsum]);
          }
          else{
            mp[digitsum]=nums[i];
          }
       } 

        return ans;
    }
};