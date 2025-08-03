class Solution {
public:
typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
       int n=nums.size();
        int ans=0;
       vector<unordered_map<ll, ll>> mp(n);
       for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff = (ll)nums[i]-(ll)nums[j];
                auto it=mp[j].find(diff);
                ll ctatj;
                if(it!=mp[j].end()){
                     ctatj=it->second;
                }
                else{
                    ctatj=0;
                }
                mp[i][diff]+=ctatj+1;
                ans+=ctatj;
            }
       }
       return ans;
    }
};