class Solution {
public:
    int minFlips(int a, int b, int c) {
        int r1=((a|b)^c);
        int r2=r1&(a&b);
      
        return __builtin_popcount(r1)+__builtin_popcount(r2); 
    } 
};
/* 
  Approach1
     num&1==>rightmost bit
    right shift ==> 1001==> 0100 >>=1
Approach2
    (a|b)^c one bits
    but 2 ones only one flip 
    a&b-->twice ones 
    a&b &  (a|b)^c gives 1 1 0 pairs ka extra wala count
__builtin_popcount gives ones


*/