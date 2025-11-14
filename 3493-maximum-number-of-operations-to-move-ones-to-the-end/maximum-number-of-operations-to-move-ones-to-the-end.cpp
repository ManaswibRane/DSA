class Solution {
public:
    int maxOperations(string s) {
        int i=0,n=s.length();
        int onect=0;
        int ans=0;
        while(i<n){
           if(s[i]=='1'){
            onect++;
                i++;

           }
           else{
               ans+=onect;
               while(i< n && s[i]=='0'){
                   i++;
               }
           }
        
        }
        return ans;
    }
};