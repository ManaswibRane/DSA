class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> tmkoc;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmkoc.push_back(grid[i][j]);
            }
        }

        // Sort the array to find the median
        sort(tmkoc.begin(), tmkoc.end());
        int size = tmkoc.size();
        int median = tmkoc[size / 2]; 

        int ans = 0;

        for (int i = 0; i < size; i++) {
            int diff = abs(tmkoc[i] - median);
            
            if (diff % x != 0) {
                return -1;
            }
            
            ans += diff / x;
        }
       
        return ans;
    }
};
