class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n));
        if(n==1){
            return matrix[0][0];
        }
        for(int i=0;i<n;i++){
            ans[0][i]=matrix[0][i];
        }
        int res=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){

                if(j==0){
                    ans[i][j]=min(ans[i-1][j+1],ans[i-1][j])+matrix[i][j];
                }
                else if(j==n-1){
                      ans[i][j]=min(ans[i-1][j-1],ans[i-1][j])+matrix[i][j];
                }
                else{
                        ans[i][j]=min({ans[i-1][j-1],ans[i-1][j],ans[i-1][j+1]})+matrix[i][j];
                }
                if(i==n-1){
                      res=min(res,ans[i][j]);
                }
            }
        }
        return res;
    }
};