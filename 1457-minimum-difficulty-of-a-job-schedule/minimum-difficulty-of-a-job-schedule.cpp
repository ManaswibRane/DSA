class Solution {
public:
    int t[301][11];
    int solve(vector<int>&jobD,int d,int n,int idx){
        if(d==1) return *max_element(jobD.begin()+idx,jobD.end());
        if(t[idx][d]!=-1){
             return t[idx][d];
        }
        int Max=INT_MIN;
        int res=INT_MAX;
        for(int i=idx;i<=(n-d);i++){
            Max=max(Max,jobD[i]);
            res=min(res,Max+solve(jobD,d-1,n,i+1));
        }
        return t[idx][d]=res;
    }
    int minDifficulty(vector<int>& jobD, int d) {
        int n=jobD.size();
        memset(t,-1,sizeof(t));
        if(d>n) return -1;
        return solve(jobD,d,n,0);
    }
};