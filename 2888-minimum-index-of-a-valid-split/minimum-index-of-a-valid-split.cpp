class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
         unordered_map<int,int> totalfreq;
         for(int i=0;i<n;i++){
              totalfreq[nums[i]]++;
         }
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
           int min;
            freq[nums[i]]++;
            if(i%2==0){
              min=i/2;
            }
            else{
                min=(i/2)+1;
            }
        if(freq[nums[i]]>min){
            int nexthalf=totalfreq[nums[i]]-freq[nums[i]];
            if(nexthalf>(n-i-1)/2) return i;
        }
        }
        return -1;
    }
};