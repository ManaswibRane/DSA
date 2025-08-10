class Solution {
public:

    void solve(vector<int>& candidates, int target,vector<vector<int>> &ans,int idx,vector<int> &curr){
               if(target<0) return;
               if(target==0) {
                     sort(curr.begin(),curr.end());
                           ans.push_back(curr);
                           return;
               }
                for(int i=idx;i<candidates.size();i++){
                    if((i>idx && candidates[i-1]==candidates[i])){
                         continue;     
                    }
                          curr.push_back(candidates[i]);
                            solve(candidates,target-candidates[i],ans,i+1,curr);
                            curr.pop_back();
                         
                }
               
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> curr;
       sort(candidates.begin(),candidates.end());
       solve(candidates,target,ans,0,curr);
       return ans;   
    }
};