class Solution {
public:
bool isVowel(char ch){
    ch=tolower(ch);
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return true;
    }
    else{
        return false;
    }
}
    string sortVowels(string s) {
        vector<char> vowelsB={'A','E','I','O','U'};
        vector<char> vowelsS={'a','e','i','o','u'};
         unordered_map<char,int> mp;
         for(char c : s){
             if(isVowel(c)){
                mp[c]++;

             }
         }
       
         for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(!isVowel(ch)){
                s[i]=s[i];
            }
            else{
                bool done=false;
                 for(char v : vowelsB){
                    if(mp[v]>0){
                        mp[v]--;
                        s[i]=v;
                        done=true;
                        break;
                    }
                 }
                 if(!done){
                          for(char v : vowelsS){
                          if(mp[v]>0){
                             mp[v]--;
                             s[i]=v;
                             break;
                         }
                      } 
                
                 }
            }
         }
         return s;
    }
};