class Solution {
public:
  int mod=1000000007;
    int numOfSubarrays(vector<int>& arr) {
        int sum=0;
        int ect=1,oct=0;

        int n=arr.size();
         
           int ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
           
             if(sum%2==0){
                ans+=oct;
            }
            else{
                ans+=ect;
            }
             if (sum % 2 == 0) ect++;
               else oct++;

          ans=ans%mod;
        }
        return ans;

       
    }
};