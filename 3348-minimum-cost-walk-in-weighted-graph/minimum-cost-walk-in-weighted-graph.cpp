class Solution {
public:
     vector<int> parent;
     int find(int x){
           if (parent[x]==x) return x;
              return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        parent[y]=x;
    }
     vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            cost[i]=-1;
        }
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            int u_parent=find(u);
            int v_parent=find(v);
            if(u_parent!=v_parent){
                Union(u_parent,v_parent);
                cost[u_parent]&=cost[v_parent];
            }
            cost[u_parent]&=w;
        }
            vector<int> res;
            for(auto q:query){
                int x=q[0],y=q[1];
                if(x==y){
                    res.push_back(0);
                    continue;
                }
                int p_x=find(x);
                int p_y=find(y);
                if(p_x!=p_y){
                    res.push_back(-1);
                }else{
                        res.push_back(cost[p_y]);
        
    }
            }
            return res;
     }
};