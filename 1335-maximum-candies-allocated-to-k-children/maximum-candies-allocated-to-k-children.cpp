class Solution {
public:
     bool maxCandy(int maxC,vector<int>& c, long long k){
       
        long long ans=0;

              for(int i=0;i<c.size();i++){
                  ans=ans+c[i]/maxC;
                  if(ans>=k) return true;
               }
                 return false;

        }
     int maximumCandies(vector<int>& c, long long k) {
        int maxC=0;
         int ans=0;
         for(int candy: c){
           maxC=max(maxC,candy);
         }
          int st=1,end=maxC;
         while(end>=st){
            int mid=st+(end-st)/2;
          if(maxCandy(mid,c,k)) {ans=mid;st=mid+1;}
          else{
            end=mid-1;
          }
        
      }
     

     return ans;
    }
};
