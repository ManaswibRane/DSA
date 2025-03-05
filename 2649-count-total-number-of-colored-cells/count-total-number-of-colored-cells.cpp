class Solution {
public:
    long long coloredCells(int n) {
        long long sum=1LL+((8LL+(n-2)*4LL))*(n-1)/2;
       
      return sum;
  }
};