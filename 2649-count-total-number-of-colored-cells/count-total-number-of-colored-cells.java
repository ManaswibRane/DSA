class Solution {
    public long coloredCells(int n) {
        long change=4;
        long base=1;
        while(n>1){
            n--;
           base+=change;
           change+=4;
        }
        return base;
    }
}