class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        string ans="";
        if(n<=2) return s;
        for(int i=1;i<n;i++){
          if(s[i-1]!=s[i] || s[i]!=s[i+1]){
                ans+=s[i-1];
            if(i==n-1) ans+=s[i];
           }
        }
        return ans;
    }
};