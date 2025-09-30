class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> vec1(26,0);
        vector<int> vec2(26,0);
        for(char ch: s){
            char ch2=tolower(ch);
            if(ch==ch2){
                  vec1[ch-'a']++;
            }
            else{
                vec2[ch-'A']++;
            }
        }
        int ans=0;
        bool mid=false;
        for(int i=0;i<26;i++){
            int x=vec1[i]%2;
              ans+=vec1[i]-x;
              cout<<i<<" "<<vec2[i]<<endl;
              if(x!=0){
                mid=true;
              }

        }
         for(int i=0;i<26;i++){
            int x=vec2[i]%2;
              ans+=vec2[i]-x;
              cout<<i<<" "<<vec2[i]<<endl;
              if(x!=0){
                mid=true;
              }

        }
        if(mid){
            ans++;
        }
        return ans;

    }
};