class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> mp;
        for(int x: friends){
            mp.insert(x);

        }
        vector<int> ans;
        for(int x: order){
            if(mp.find(x)!=mp.end()){
                ans.push_back(x);
            }
        }
        return ans;
    }
};