class Solution {
public:
    typedef pair<int,int>P ;
     typedef pair<long long,int> p ;
     static constexpr int mod = 1000000007; 


    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<P>> adj;
        for(auto road: roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];
            adj[u].push_back({v,time});
             adj[v].push_back({u,time});
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<long long> result(n,LLONG_MAX);
        vector<int> path(n,0);
        result[0]=0;
        path[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto t=pq.top();
            long long currTime=t.first;
            int currNode=t.second;
            pq.pop();
            for(auto &vec:adj[currNode]){
                int nbr=vec.first;
                int roadTime=vec.second;
                if( (currTime+roadTime) <result[nbr] ){
                    result[nbr]=currTime+roadTime;
                    pq.push( {result[nbr],nbr});
                    path[nbr]=path[currNode];
                }else if((currTime+roadTime)==result[nbr] ){
                      path[nbr]=(1LL*path[currNode]+ path[nbr])%mod;
                }
            }
        }
        return path[n-1];

    }
};