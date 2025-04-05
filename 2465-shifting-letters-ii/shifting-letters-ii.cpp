class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> diffArray(n,0);
        for(auto shift: shifts){
            int st=shift[0];
            int end=shift[1];
            int q=shift[2];
            if(q==0) {q=-1;}
            diffArray[st]+=q;
            if( (end+1) < n) diffArray[end+1]-=q;
        }
        int sum=0;
        for(int i=0;i<n;i++){
           diffArray[i]+=sum;
           sum=diffArray[i];
    
             diffArray[i]= diffArray[i]%26;
         if(diffArray[i]<0){
            diffArray[i]+=26;

         }
         s[i]=( ((s[i]-'a') + diffArray[i]) % 26) +'a';

        }
      return s;
    }
};