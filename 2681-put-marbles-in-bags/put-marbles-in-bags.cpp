class Solution {
public:
    long long putMarbles(vector<int>& wts, int k) {
          int n=wts.size();
          int j=0;
          vector<long long> sum;
       while(j<n-1){
           sum.push_back( (long long)wts[j+1]+ (long long)wts[j]);
           j++;

       }
       sort(sum.begin(),sum.end());
       int i=0,x=sum.size();
       long long ans=0;

       while(i< k-1){
            ans=ans-sum[i];
            ans+=sum[x-i-1];
            i++;
       }
       i=0;
       return ans;
    }
};