class Solution {
public:
    int minimumRecolors(string b, int k) {
      int n=b.length(),ans=INT_MAX;
      for(int i=0;i<=n-k;i++){
        int count=0;
        for(int j=i;j<i+k;j++){
            if(b[j]=='W'){
                count++;
            }

        }
        ans=min(ans,count);
      }
      return ans;
    }
};