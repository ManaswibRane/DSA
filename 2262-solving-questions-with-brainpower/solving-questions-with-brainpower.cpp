class Solution {
public:
int n;
    long long solve(int i,vector<vector<int>>& q,vector<long long>& t){
        if(i>=q.size()) return 0;
        if(t[i]!=-1) return t[i];
        long long taken=q[i][0]+solve(i+q[i][1]+1,q,t);
        long long notTaken=solve(i+1,q,t);
        return t[i]=max(taken,notTaken);
    }
    long long mostPoints(vector<vector<int>>& q) {
        n=q.size();
        vector<long long> t(n+1,-1);
        return solve(0,q,t);
    }
};