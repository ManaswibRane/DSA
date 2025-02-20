class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mp;
        int m=grid.size(),n=grid[0].size();
        int ct=0;
        for(int i=0;i<m;i++){
           mp[grid[i]]++;
        }
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<m;j++){
                temp.push_back(grid[j][i]);
            }
            if(mp.count(temp)){
                 ct+=mp[temp];
            }
        }
        return ct;
        
    }
};