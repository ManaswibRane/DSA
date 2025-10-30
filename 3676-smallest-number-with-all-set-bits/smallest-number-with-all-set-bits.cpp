class Solution {
public:
    int smallestNumber(int n) {
         int x=0;
         for(int i=0;i<32;i++){
            if(x>=n){
                return x;
            }
            x+=(1<<i);
         }
         return -1;
    }
};