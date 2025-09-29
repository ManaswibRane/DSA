class Solution {
public:
vector<string> result;
int c,r;
vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

struct trieNode{
    bool eow;
    trieNode* child[26];
    string s;

};
trieNode* getNode(){
    trieNode* newNode=new trieNode();
    for(int i=0;i<26;i++){
        newNode->child[i]=NULL;

    }
    newNode->eow=false;
    newNode->s="";
    return newNode;
}
void insert(trieNode* root,string str){
    trieNode* crawler=root;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(crawler->child[ch-'a']==NULL){
            crawler->child[ch-'a']=getNode();
        }
        crawler=crawler->child[ch-'a'];
    }
    crawler->eow=true;
    crawler->s=str;
}
void findWords(vector<vector<char>>& board,int i,int j,trieNode* root){
      if(i>=r || j>=c || i<0 || j<0){
        return ;
      }
      if( board[i][j]=='$'  || root->child[board[i][j]-'a']==NULL){
        return;
      }
      char ch=board[i][j];
      root=root->child[board[i][j]-'a'];
      if(root->eow==true){
        result.push_back(root->s);
        root->eow=false;
      }
      board[i][j]='$';
      for(pair<int,int> d : dir){
        int new_i=i+d.first;
        int new_j=j+d.second;
        findWords(board,new_i,new_j,root);

      }
       board[i][j]=ch;
}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       r=board.size();
       c=board[0].size();
       trieNode* root=getNode();
       for(string word : words){
           insert(root,word);
       }
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
                 char ch=board[i][j];
                 if(root->child[ch-'a']!=NULL){
                    findWords(board,i,j,root);
                 }
             }
       }
       return result;
    }
};