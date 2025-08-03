class Solution {
public:
   struct TrieNode{
        TrieNode* children[26];
        bool eol;
        string word;
    };
    TrieNode* getNode(){
        TrieNode* newNode=new TrieNode();
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        } 
         newNode->eol=false;
         return newNode;
    }
        void insert(TrieNode* root, string str) {
        TrieNode* pCrawl = root;
        for(char ch:str) {
            if(pCrawl->children[ch-'a'] == NULL) {
                pCrawl->children[ch-'a'] = getNode();
            }
            pCrawl = pCrawl->children[ch-'a'];
        }
        pCrawl->eol = true;
        pCrawl->word = str;
    }
    string search( TrieNode* root,string s){
        TrieNode* crawler=root;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(!crawler->children[idx]){
                return s;
            }
            crawler=crawler->children[idx];
            if(crawler->eol){
                s=s.substr(0,i+1);
                return s;
            }

        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
          TrieNode* root=getNode();
          for(string s : dictionary){
                insert(root,s);
          }
          string ans="";
          int n=sentence.length();
          string s="";
          for(int i=0;i<n;i++){
             if(sentence[i]!=' '){
                s+=sentence[i];
               
             }
            
             else if(i!=n-1){
                string sub=search(root,s);
                ans+=sub+" ";
                s="";
             }
            
          }
            if(!s.empty()){
                  string sub=search(root,s);
                    ans+=sub;
             }
          return ans;
    }
};