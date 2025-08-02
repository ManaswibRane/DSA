class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int ct1=0,ct2=0;
          int el1=-1,el2=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
               ct1++;
            }
            else if(nums[i]==el2){
                ct2++;
            }
            else if(ct1==0){
                ct1=1;
                el1=nums[i];
             } 
             else if(ct2==0){
                ct2=1;
                el2=nums[i];
             }
             else{
                ct1--;
                ct2--;
             }
       }

         int ans1=0,ans2=0;
         for(int i=0;i<n;i++){
             if(nums[i]==el1){
                ans1++;
             }
                else if(nums[i]==el2){
                ans2++;
             }
       }
       vector<int> ans;
        if(ans1>(n/3)){
                ans.push_back(el1);
             }
         if(ans2>(n/3)){
                ans.push_back(el2);
             }
             return ans;
    }
};