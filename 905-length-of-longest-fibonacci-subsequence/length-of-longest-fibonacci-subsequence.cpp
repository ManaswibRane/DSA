class Solution {
public:
    int solve(int i, int j, vector<int>& arr, unordered_map<int, int>& mp, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];  // Use memoization to avoid recomputation
        
        int check = arr[i] - arr[j];
        if (check >= arr[j] || mp.find(check) == mp.end()) return dp[i][j] = 2;

        int k = mp[check];
        if (k >= j) return dp[i][j] = 2;  // Prevent invalid recursion

        return dp[i][j] = solve(j, k, arr, mp, dp) + 1;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;  // Base case: Fibonacci sequence needs at least 3 elements

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[arr[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n, -1));  // Memoization table
        int maxLength = 0;

        for (int i = 2; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                maxLength = max(maxLength, solve(i, j, arr, mp, dp));
            }
        }

        return maxLength > 2 ? maxLength : 0;  // If no sequence found, return 0
    }
};
