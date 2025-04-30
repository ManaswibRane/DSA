class Solution {
public:
bool isEven(int x){
    int digits=0;
   while(x>0){
     x/=10;
     digits++;
   }
   if(digits%2==0) return true;
   return false;
}
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(isEven(nums[i])){
                 ans++;
            }
        }
        return ans;

    }
};