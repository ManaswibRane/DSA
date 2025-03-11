class Solution {
public:
  bool allPres(vector<int> &vec){
    return (vec[0]>=1 && vec[1]>=1 && vec[2]>=1 );
  
  }
    int numberOfSubstrings(string s) {
        int l=s.length();
        vector<int> ct(3,0);
        int i=0,j=0,ans=0;
        while(j<l){
            ct[s[j]-'a']++;
             while (allPres(ct)) {
                ans += l - j; 
                ct[s[i] - 'a']--; 
                i++;
            }
              j++;
        }
        return ans;
    }
};