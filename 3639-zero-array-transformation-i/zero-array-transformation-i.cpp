class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diffArray(n,0);
        for(auto query: queries){
            int st=query[0];
            int end=query[1];
            diffArray[st]--;
            if(end+1 <n) diffArray[end+1]++;
           
        }
        int sum=0;
        for(int i=0;i<n;i++){
            diffArray[i]+=sum;
            sum=diffArray[i];
            if( (diffArray[i]+nums[i])>0 ){
                return false;
            }
        }
        return true;
    }
};