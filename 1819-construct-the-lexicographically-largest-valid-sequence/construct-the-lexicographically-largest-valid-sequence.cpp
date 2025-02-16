class Solution {
public:
    bool solve(int i, int n, vector<int>& res, unordered_map<int, bool>& used) {
        if (i >= res.size()) {
            return true;
        }
        if (res[i] != 0) {
            return solve(i + 1, n, res, used);
        }
        
        for (int num = n; num > 0; num--) {
            if (used[num]) {
                continue;
            }
            
            used[num] = true;
            res[i] = num;

            if (num == 1) {
                if (solve(i + 1, n, res, used)) {
                    return true;
                }
            } else {
                int j = i + num;
                if (j < res.size() && res[j] == 0) {
                    res[j] = num;
                    if (solve(i + 1, n, res, used)) {
                        return true;
                    }
                    res[j] = 0;  // Backtrack
                }
            }

            res[i] = 0;  // Backtrack
            used[num] = false;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        unordered_map<int, bool> used;
        vector<int> res(2 * n - 1, 0);
        solve(0, n, res, used);
        return res;
    }
};
