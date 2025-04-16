class Solution {
public:
//   long long fact(int n){
//        if(n<=1){
//         return 1;
//            }
//        return n*fact(n-1);
//     }
//    long long permutation(int n,int r){
//        long long ans=fact(n)/(fact(n-r)*fact(r));
//        return ans;
//   }
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int pairs=0;
        long long ans=0;
        unordered_map<int,int> mp;
       int i=0,j=0;
       while(j<n){
        pairs+=mp[nums[j]];
        mp[nums[j]]++;
        while(pairs>=k){
            ans+=n-j;
           mp[nums[i]]--;
            pairs-=mp[nums[i]];
            i++;
        }
          j++;
       }
       return ans;

    }
};