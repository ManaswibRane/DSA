class Solution {
public:

    int nthUglyNumber(int n) {
          vector<int> arr(n+1);
          int i2=1,i3=1,i5=1;

          arr[1]=1;
          for(int i=2;i<=n;i++){
            int ugly2=arr[i2]*2;
            int ugly3=arr[i3]*3;
            int ugly5=arr[i5]*5;
            int minUgly=min({ugly2,ugly3,ugly5});
            if(minUgly==ugly2){
                i2++;
            }
             if(minUgly==ugly3){
                i3++;
            }
             if(minUgly==ugly5){
                i5++;
            }
                 arr[i]=minUgly;

          }
          return arr[n];
    }
};