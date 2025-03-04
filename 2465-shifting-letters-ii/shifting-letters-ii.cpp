class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int m = s.length();
        vector<int> count(m + 1, 0); 
        for (const auto& i : sh) {
            int st = i[0], end = i[1], x = i[2];
            if(x==0) x=-1;
            count[st] += x;  
            if (end + 1 < m) count[end + 1] -= x;  
        }


        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += count[j];
            count[j] = sum;
        } 
        for (int j = 0; j < m; j++) {
            
            s[j] = 'a' + ( (s[j] - 'a' + count[j]) % 26 + 26 ) % 26; 
        }

        return s;
    }
};
