class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int st_row=0,st_col=0,end_row=matrix.size()-1,end_col=matrix[0].size()-1;
        while(st_row<=end_row && st_col<=end_col){
            for(int i=st_col ; i<=end_col;i++){
                ans.push_back(matrix[st_row][i]);
            }
             st_row++;
             for(int i=st_row ; i<=end_row;i++){
                ans.push_back(matrix[i][end_col]);
            }
            end_col--;
          if (st_row <= end_row) {
                for (int i = end_col; i >= st_col; i--)
                    ans.push_back(matrix[end_row][i]);
                end_row--;
            }

            
            if (st_col <= end_col) {
                for (int i = end_row; i >= st_row; i--)
                    ans.push_back(matrix[i][st_col]);
                st_col++;
            }
            
         

        }
        return ans;
    }
};