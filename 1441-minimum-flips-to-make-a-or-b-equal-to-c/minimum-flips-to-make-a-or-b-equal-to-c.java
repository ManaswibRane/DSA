class Solution {
    public int minFlips(int a, int b, int c) {
        int flips;
        int temp=(a|b)^c;
        int temp2=(a&b)&(temp);
        flips=Integer.bitCount(temp)+Integer.bitCount(temp2);
          return flips;
    }
}