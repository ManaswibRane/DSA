class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> og0,og1;
        og0.push_back(0);
        og1.push_back(1);
        for(int i=1;i<n;i++){
           og0.push_back(og0[i-1]^derived[i-1]);
              og1.push_back(og1[i-1]^derived[i-1]);
        }
    int x1=og0[0]^og0[n-1], x2=og1[0]^og1[n-1];
    if(x1==derived[n-1] || x2==derived[n-1]) return true;
    return false;
    }
};