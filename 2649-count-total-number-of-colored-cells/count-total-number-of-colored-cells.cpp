class Solution {
public:
    long long coloredCells(int n) {
        long long sum=1;
        int x=4;

       for(int i=0;i<n-1;i++){
        sum+=x;
        x+=4;
       }
        
        return sum;
    }
};