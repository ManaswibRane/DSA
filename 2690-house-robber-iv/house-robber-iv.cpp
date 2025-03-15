class Solution {
public:
    bool solve(int mid,vector<int>& nums, int &k){
        int house=0;
             for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid){ i++; house++;}
             }
             return house>=k;
    }
    int minCapability(vector<int>& nums, int k) {

          int l=*min_element(nums.begin(),nums.end()) ;
          int r=*max_element(nums.begin(),nums.end()) ;
          int res=r;
          while(l<=r){
            int mid=r+(l-r)/2;
            if(solve(mid,nums,k)) {
                 res=mid;
                 r=mid-1;
                 }
                 else{
                    l=mid+1;
                 }
          }
          return res;
    }
};