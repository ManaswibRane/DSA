class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rep,miss,n=grid.size();
        unordered_map<int,int> ct;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ct[grid[i][j]]++;
            }
        }
        for(int i=1;i<=n*n;i++){
            if(ct.count(i)==0){
                miss=i;
            }
            else if(ct[i]==2){
                rep=i;
            }
        }
        return {rep,miss};
    }
};