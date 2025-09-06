class Solution {
public:
    long long solve(int l,int r){
        long long s=1;
        long long L=1;
        long long lesse=0;
        while(L<=r){
            long long R= 4*L-1;
            long long mn=max(L,(long long)l);
            long long mx=min(R,(long long)r);
            long long ele=mx-mn+1;
            if(ele>0){

                lesse+=ele*s;
            }
            s++;
            L*=4;
        }
        return lesse;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long sum=0;
          for(auto query: queries){
             int l=query[0],r=query[1];
           long long ans=  solve(l,r);
           sum+=(ans+1)/2;
          } 
          return sum;



    }
};