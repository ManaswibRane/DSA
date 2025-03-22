class Solution {
public:
   void dfs(int i, unordered_map<int,vector<int>>& adj,  vector<bool>& Visited,int &v,int &e){
         Visited[i]=true;
         e+=adj[i].size();
         v++;
         for(int ele: adj[i]){
            if( !Visited[ele]){
              dfs(ele,adj,Visited,v,e);  
            }
         }
   }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        int res=0;
        for(auto edge: edges){
           int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
             adj[v].push_back(u);
        }
        vector<bool> Visited(n,false);
        for(int i=0;i<n;i++){
            if(Visited[i]==true){
                continue;
            }
            int v=0;
            int e=0;
            dfs(i,adj,Visited,v,e);
            if((v*(v-1))==e){
                res++;
            }
        }
        return res;
    }
};