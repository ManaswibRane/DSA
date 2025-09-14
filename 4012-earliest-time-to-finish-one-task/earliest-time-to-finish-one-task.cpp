class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minFinish=INT_MAX;
        for(int i=0;i<tasks.size();i++){
            int st=tasks[i][0];
            int t=tasks[i][1];
            int finish=st+t;
            minFinish=min(finish,minFinish);
        }
        return minFinish;
    }
};