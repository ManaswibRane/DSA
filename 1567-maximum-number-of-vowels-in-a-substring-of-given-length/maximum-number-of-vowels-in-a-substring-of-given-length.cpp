class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0,j=0;
        int ans=INT_MIN;
        int temp=0;
        while(j<n){
              if(s[j]=='a' || s[j]=='e' ||s[j]=='i' ||s[j]=='o' ||s[j]=='u'){
            
                 temp++;
             }
            if(j-i+1==k){
                ans=max(ans,temp);
                 if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                temp--;
           
             }
                  i++;
            }
           
         j++;
        }
        return ans;
    }
};