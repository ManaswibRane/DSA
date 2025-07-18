class Solution {
public:
typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
         int n=nums.size();
         unordered_map<ll,ll> mp[n];
         ll res=0;
         for(int i=0;i<n;i++){
              for(int j=0;j<i;j++){
                ll diff=(ll)nums[i]-(ll)nums[j];
                   ll count=0;

               auto it=mp[j].find(diff);
                 if(it!=mp[j].end()){
                       count=mp[j][diff];
                        res+=count;
                      
             }
                  mp[i][diff]+=count+1;
                
              }
         }
         return res;
    }
};