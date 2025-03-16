class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
         int ans=0;
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n1;i++){
        if(n2%2==1){
            ans=ans^nums1[i];
        }
        else{
            break;
        }
        }
         for(int i=0;i<n2;i++){
        if(n1%2==1){
            ans=ans^nums2[i];
        }
        else{
            break;
        }
        }
        return ans;
    }
};