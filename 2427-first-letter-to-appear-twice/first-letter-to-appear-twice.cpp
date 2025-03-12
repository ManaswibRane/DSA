class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> ch;
        char ans;
        for(int i=0;i<s.length();i++){
            if(ch.find(s[i])!=ch.end()) {ans=s[i];break;}
            ch.insert(s[i]);
        }
        return ans;
    }
};