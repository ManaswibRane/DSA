class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> mp;
        for(char ch : brokenLetters){
            mp.insert(ch);
        }
        int ans=0;
        int n=text.size();
        for(int i=0;i<n;i++){
            char ch=text[i];
            if(mp.find(ch)!=mp.end()){
                while(i<n && text[i]!=' '){
                    i++;
                }
              
            }
            else if(text[i]==' '){
                cout<<i<<" ";
                ans++;
            }
            if(i==n-1 && mp.find(text[n-1])==mp.end()){
                 cout<<i<<" ";
                ans++;
            }
        }
          return ans;
    }
};