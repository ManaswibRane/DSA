class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        int n = n1.size(), m = n2.size();
        int soi = n + m;
        vector<int> vec;
        int i = 0, j = 0;
        while (i < n || j < m) {
            if (i < n && (j >= m || n1[i] < n2[j])) {
                vec.push_back(n1[i++]);
            } else {
                vec.push_back(n2[j++]);
            }

           
            if (vec.size() > soi / 2) break;
        }

    
        if (soi % 2 == 0) {
            return (vec[soi / 2] + vec[soi / 2 - 1]) / 2.0;
        } else {
            return vec[soi / 2];
        }
    }
};
