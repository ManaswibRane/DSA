class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
       
        int n=nums.size();
         vector<bool> answer(n,true);
           long long num=0;
        for(int i=0;i<n;i++){
          
        
               num = (num * 2 + nums[i]) % 5; 
        
            if(num%5!=0) answer[i]=false;
        }
        return answer;
    }
};