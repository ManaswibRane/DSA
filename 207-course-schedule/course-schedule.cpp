class Solution {
public:
   bool kahns( unordered_map<int,vector<int>>& mp,int n){
        queue<int> q;
        vector<int> inD(n,0);
        for(auto it : mp){
            for(int x : it.second){
                inD[x]++;
            }
        }
        for(int i=0;i<n;i++){
            if(inD[i]==0){
                q.push(i);
            }

        }
        int ct=0;
        while(!q.empty()){
            int a=q.front();
              q.pop();
              ct++;
              for(int x : mp[a]){
                inD[x]--;
                if(inD[x]==0){
                    q.push(x);
                }
              }
        }
        if(ct==n){
            return true;
        }
        else{
            return false;
        }
   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int,vector<int>> mp;
         int n=prerequisites.size();
         for(auto it : prerequisites){
            int a=it[0];
            int b=it[1];
            mp[b].push_back(a);
           
         }
          if(!kahns(mp,numCourses)){
                return false;
            } else{
                return true;
            }
    }
};