class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct=0;
        int el;
        int n=nums.size();
        for(int i=0;i<n;i++){
             if(ct==0){
                ct=1;
                el=nums[i];
             } 
             else if(nums[i]!=el){
                ct--;
             }
             else{
                ct++;
             }
       }
         int ans=0;
         for(int i=0;i<n;i++){
             if(nums[i]==el){
                ans++;
             }
       }
        if(ans>=(n/2)){
                return el;
             }
             else{
                return -1;
             }
     

    }
};