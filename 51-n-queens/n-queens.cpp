class Solution {
public:
bool isSafe(vector<string>& board,int row,int col,int n){
    //check col
    for(int i=row-1;i>=0;i--){
        if(board[i][col]!='.') return false;
    }
    for(int i=col+1;i<n;i++){
         if(board[row][i]!='.') return false;
    }
    int c=col+1;
    for(int i=row-1;i>=0;i--){
        if(c<n && board[i][c++]!='.') return false;
    }
    c=col-1;
     for(int i=row-1;i>=0;i--){
        if(c>=0 && board[i][c--]!='.') return false;
    }
    return true;
}
    void solve( vector<string> &board, vector<vector<string>> &ans,int row,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
               if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                solve(board,ans,row+1,n);
                board[row][col]='.';
               }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

      vector<string> board(n, string(n, '.'));
       vector<vector<string>> ans;
       solve(board,ans,0,n);
       return ans;
    }
};
