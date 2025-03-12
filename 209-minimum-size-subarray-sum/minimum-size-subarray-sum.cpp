class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
      int n=nums.size();
      int ans=INT_MAX;
      int i=0,j=0;
      int sum=0,ele=0;
      while(j<n){
        ele++;
           sum+=nums[j];
           if(sum>=t){
            int temp=i,tempsum=sum,tempele=ele;

            while(temp<n && tempsum>=t){
                tempsum-=nums[temp++];
                tempele--;
            }
            ans=min(ans,tempele);
            sum-=nums[i];
             ele--;

            i++;
           }
           j++;
      }
      if(ans==INT_MAX) return 0;
      return ans+1;
    }
};