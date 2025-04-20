class Solution {
public:
   void solve(vector<string>& ans,int open,int close,int n,string temp){
    if(open==n && close==n){
        ans.push_back(temp);
        return;
    }
     if(open<n){
        solve(ans,open+1,close,n,temp+"(");
        
     }
       if(close<open){
        solve(ans,open,close+1,n,temp+")");
        
     }
   }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        solve(ans,0,0,n,temp);
        return ans;

    }
};
