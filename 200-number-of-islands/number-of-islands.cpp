
class Solution {
public:
typedef long long ll;
vector<vector<ll>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
bool isValid(ll i,ll j,ll n,ll m)
{
    if(i<n && j<m && i>=0 && j>=0){
        return true;
    }
    return false;
}
void dfs(ll i,ll j,ll n,ll m, vector<vector<bool>> &visited,vector<vector<char>>& grid){
       for(auto dir: dirs){
           ll i_=i+dir[0];
           ll j_=j+dir[1];
           if(isValid(i_,j_,n,m) && grid[i_][j_]=='1' && !visited[i_][j_]){
            visited[i_][j_]=true;
              dfs(i_,j_,n,m,visited,grid);
           }
       } 
}
    int numIslands(vector<vector<char>>& grid) {
        ll n=grid.size();
        ll m=grid[0].size();
        int ans=0;
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    ans++;
                    visited[i][j]=true;
                    dfs(i,j,n,m,visited,grid);
                }
            }
        }
        return ans;
    }
};