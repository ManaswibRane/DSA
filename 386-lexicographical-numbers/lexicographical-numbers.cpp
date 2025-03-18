class Solution {
public:
    void solve(int curr,int n,vector<int> &ans){
        if(curr>n){
            return;
        }
        ans.push_back(curr);
        for(int i=0;i<=9;i++){
            int num=curr*10+i;
            solve(num,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int stnum=1;stnum<=9;stnum++){
            solve(stnum,n,ans);
        }
        return ans;
    }
};