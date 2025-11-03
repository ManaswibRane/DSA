class Solution {
public:
vector<pair<int,int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m,vector<char> (n,'.'));
        queue<vector<int>> q;
        for(auto guard: guards){
            grid[guard[0]][guard[1]]='G';
            q.push(guard);
        }
        for(auto wall: walls){
            grid[wall[0]][wall[1]]='W';
            
        }
        
        while(!q.empty()){

            auto tp=q.front();
            q.pop();
            int i=tp[0],j=tp[1];
            if(grid[i][j]=='G'){
                int ct=0;
                  for(auto dir : dirs){
                    
                    int i_=i+dir.first,j_=j+dir.second;
                    if(i_>=0 && i_<m && j_>=0 && j_<n){
                        if(grid[i_][j_]!='W' && grid[i_][j_]!='G'){
                            grid[i_][j_]='X';
                           q.push({i_,j_,ct});

                        }
                    }
                    ct++;
                  }

            }
            else{
                int i_=i+dirs[tp[2]].first,j_=j+dirs[tp[2]].second;
                if(i_>=0 && i_<m && j_>=0 && j_<n){
                    if(grid[i_][j_]!='W' && grid[i_][j_]!='G'){
                                    grid[i_][j_]='X';
                                     q.push({i_,j_,tp[2]});
                         }
                }
                
             
            }
           


        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='.'){
                    ans++;
                }
            }
        }
        return ans;

    }
};