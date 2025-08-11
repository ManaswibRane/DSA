class Solution {
    public double myPow(double a, int n) {
             double ans = 1;
             long pow=n;
        if(pow<0) {
            a=1/a;
             pow=-pow;
        }
       
        while(pow>0){
            if((pow&1)!=0){
                ans=ans*a;

            }
            a=a*a;
            pow=pow>>1;
        }
    
    return ans;
    }
}