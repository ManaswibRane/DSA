class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
       unordered_set<int> mp;
        for(int n: nums){
            if(mp.find(n)!=mp.end()) return n;
            mp.insert(n);
        }
        return -1;
    }
};