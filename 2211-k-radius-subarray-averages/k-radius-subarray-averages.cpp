class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
            int n=nums.size();
           vector<int> ans(n,-1);
           int l=0,r=2*k;
           long long sum=0;

           for(int i=0;i<=r;i++){
            if(i>=n) return ans;
            sum+=nums[i];
           }
           while(r<n){
        
            int i=(l+r)/2;
           long long avg=sum/(k*2+1);
            ans[i]=int(avg);
            sum-=nums[l];
            l++;
                r++;
          if(r<n) sum+=nums[r];

           }
           return ans;
    }
};