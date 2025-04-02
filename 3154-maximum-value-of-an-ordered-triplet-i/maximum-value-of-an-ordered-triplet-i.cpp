class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> bigfront(n,0),bigrear(n,0);
          bigfront[0]=nums[0];
        for(int i=1;i<n;i++){
             bigfront[i]=max(nums[i-1],bigfront[i-1]);
           
        }
        bigrear[n-1]=nums[n-1];
         for(int i=n-2;i>=0;i--){
             bigrear[i]=max(nums[i],bigrear[i+1]);
            //  bigrear[n-i-1]=max(nums[n-i],bigfront[n-i]);
        }
        long long res=0;
        for(int j=1;j<n-1;j++){
               res=max(res,(long long)(bigfront[j]-nums[j])*bigrear[j+1]);
               cout<<res<<"\t"<<bigfront[j]<<"\t"<<nums[j]<<"\t"<<bigrear[j+1]<<endl;
        }
        
           return res;
    }
};