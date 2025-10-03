class Solution {
public:
    typedef pair<int,pair<int,int>> PP;
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    int trapRainWater(vector<vector<int>>& mp) {
        int n = mp.size();
        int m = mp[0].size();
        if(n == 0 || m == 0) return 0;

        priority_queue<PP, vector<PP>, greater<PP>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<m;i++){
            q.push({mp[0][i], {0,i}});
            q.push({mp[n-1][i], {n-1,i}});
            visited[0][i] = true;
            visited[n-1][i] = true;
        }
        for(int i=0;i<n;i++){
            q.push({mp[i][0], {i,0}});
            q.push({mp[i][m-1], {i,m-1}});
            visited[i][0] = true;
            visited[i][m-1] = true;
        }

        int ans = 0;
        while(!q.empty()){
            auto x = q.top(); q.pop();
            int height = x.first;
            int i = x.second.first;
            int j = x.second.second;

            for(auto d : dir){
                int i_ = i + d.first;
                int j_ = j + d.second;
                if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && !visited[i_][j_]){
                    
                    ans += max(height - mp[i_][j_], 0);
                   
                    q.push({max(height, mp[i_][j_]), {i_, j_}});
                    visited[i_][j_] = true;
                }
            }
        }
        return ans;
    }
};
