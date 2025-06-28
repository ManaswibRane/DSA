class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        List<Integer> ans = new ArrayList<>();
        int st_row = 0, st_col = 0, end_row = m - 1, end_col = n - 1;

        while (st_row <= end_row && st_col <= end_col) {
            for (int i = st_col; i <= end_col; i++)
                ans.add(matrix[st_row][i]);
            st_row++;

            for (int i = st_row; i <= end_row; i++)
                ans.add(matrix[i][end_col]);
            end_col--;

            if (st_row <= end_row) {
                for (int i = end_col; i >= st_col; i--)
                    ans.add(matrix[end_row][i]);
                end_row--;
            }

            if (st_col <= end_col) {
                for (int i = end_row; i >= st_row; i--)
                    ans.add(matrix[i][st_col]);
                st_col++;
            }
        }

        return ans;
    }
}
