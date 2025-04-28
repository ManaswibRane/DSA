class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            int temp=(1<<i);
            int ones=0;
            for(int j=0;j<nums.size();j++){
                 if( (nums[j]&temp)!=0){
                    ones++;
                 }
                 
            }
            if((ones%3)!=0){
                    res|=temp;
                 }
        }
        return res;
    }
};

/*
1<<k times and with num if 1 or 0



*/