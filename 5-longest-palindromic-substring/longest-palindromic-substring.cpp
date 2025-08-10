class Solution {
public:
    bool solve(string& s,int st,int end){
          while(st<=end){
            if(s[st++]!=s[end--]){
                return false;
               }

          }  
          return true;

    }
    string longestPalindrome(string s) {
         int n=s.length();
         int lst=0,lend=0;
         int len=1;
      
         int longst=0,longend=0;
          for(int i=0;i<n;i++){
               for(int end=i;end<n;end++){
                  if((end-i+1)>len && solve(s,i,end)){
                      lst=i;
                      lend=end;
                      len=lend-lst+1;
                  }
               }
          }
          cout<<len<<lst;
        string a=s.substr(lst,len);
           return a;
    }
};