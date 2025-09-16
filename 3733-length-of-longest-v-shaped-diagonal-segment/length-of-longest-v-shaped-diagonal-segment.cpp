class Solution {
public:
 vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
 int m,n;
 int t[501][501][4][2];
 int solve(int i,int j,int d,bool canTurn,int val,vector<vector<int>>& grid){
        int i_=i+dir[d][0];
        int j_=j+dir[d][1];
        if(i_<0 || i_>=n || j_<0 || j_>=m || grid[i_][j_]!=val){
            return 0;
        }
        if(t[i_][j_][d][canTurn]!=-1){
            return t[i_][j_][d][canTurn];
        }
        int res=0;
        res=max(res,1+solve(i_,j_,d,canTurn,val==2? 0 : 2,grid));
        if(canTurn){
             res=max(res,1+solve(i_,j_,(d+1)%4,false,val==2? 0 : 2,grid));
        }
       return t[i_][j_][d][canTurn]=res;
 }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int res=0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int d=0;d<=3;d++){
                          res=max(res,1+solve(i,j,d,true,2,grid));
                    }
                  
                }
            }
        }
        return res;
    }
};