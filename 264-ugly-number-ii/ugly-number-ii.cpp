class Solution {
public:
    int nthUglyNumber(int n) {
          vector<int> dp(n+1,1);
          int i2=1;
          int i3=1;
          int i5=1;
          for(int i=2;i<=n;i++){
               int i2Ugly=2*dp[i2];
               int i3Ugly=3*dp[i3];
               int i5Ugly=5*dp[i5];
               dp[i]=min({i2Ugly,i3Ugly,i5Ugly});
               if(dp[i]==i2Ugly){
                i2++;
               }
               if(dp[i]==i3Ugly){
                i3++;
               }
               if(dp[i]==i5Ugly){
                i5++;
               }

          }
        return dp[n];
    }
};