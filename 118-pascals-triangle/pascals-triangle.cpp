class Solution {
public:
    vector<vector<int>> generate(int rnum) {
        vector<vector<int>> ans(rnum);

        for (int i = 0; i < rnum; i++) {
            ans[i].resize(i + 1, 1);
            for (int col = 1; col < i; col++) {
                ans[i][col] = ans[i - 1][col - 1] + ans[i - 1][col];
            }
        }
        return ans;
    }
};
