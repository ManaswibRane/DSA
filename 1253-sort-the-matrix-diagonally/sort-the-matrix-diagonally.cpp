class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
     
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   int idx=i-j;
                   mp[idx].push_back(mat[i][j]);
            }
        }
        for(auto& it : mp){
            sort(it.second.begin(),it.second.end(),greater<int>());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 int idx=i-j;
                 mat[i][j]=mp[idx].back();
                 mp[idx].pop_back();
            }
        }
        return mat;
    }
};