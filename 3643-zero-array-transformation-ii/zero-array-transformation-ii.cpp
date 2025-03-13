class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& qs,int mid){
         int n=nums.size(),q=qs.size(),i=0,sum=0;
         vector<int> diff(n,0);
         while(i<=mid){
            int l=qs[i][0],r=qs[i][1],x=qs[i][2];
            diff[l]+=x;
            if(r+1<n) diff[r+1]-=x;
            i++;
         }
         for(int i=0;i<n;i++){
               sum+=diff[i];
               diff[i]=sum;
            if(nums[i]-diff[i]>0) return false;
         }
         return true;
        
         
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& qs) {
        auto alpha=[](int x){
            return x==0;
        };
           if(all_of(nums.begin(),nums.end(),alpha)) return 0;
           int n=nums.size(),q=qs.size();
           int st=0,end=q-1,ans=-1;
           while(st<=end){
               int mid=st+(end-st)/2;
               if(check(nums,qs,mid)){
                   ans=mid+1;
                   end=mid-1;
               }
               else{
                st=mid+1;
               }

           }
           return ans;
    }
};