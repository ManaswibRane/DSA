class Solution {
public:
  int solveL(vector<int>& nums, int target){
    int ans=-1;
    int n=nums.size();
    int st=0,end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]<target){
            st=mid+1;
        }
         if(nums[mid]>target){
            end=mid-1;
        }
         if(nums[mid]==target){
           ans=mid;
           end=mid-1;
        }
    }
    return ans;
  }
    int solveR(vector<int>& nums, int target){
    int ans=-1;
    int n=nums.size();
    int st=0,end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]<target){
            st=mid+1;
        }
         if(nums[mid]>target){
            end=mid-1;
        }
         if(nums[mid]==target){
           ans=mid;
           st=mid+1;
        }
    }
    return ans;
  }
    vector<int> searchRange(vector<int>& nums, int target) {
                int left=solveL(nums,target);
                int right=solveR(nums,target);  
                return {left,right} ;
    }
};