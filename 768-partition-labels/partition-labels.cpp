class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIdx;
        unordered_map<char, int> firstIdx;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (firstIdx.find(s[i]) == firstIdx.end()) {
                firstIdx[s[i]] = i;
            }
            lastIdx[s[i]] = i;
        }

        vector<int> ans;
        int i = 0;
        while (i < len) {
            int first = firstIdx[s[i]];
            int last = lastIdx[s[i]];
            int j = first;

            while (j <= last) {
                last = max(last, lastIdx[s[j]]);
                j++;
            }

            ans.push_back(j - first);
            i = j; 
        }

        return ans;
    }
};
