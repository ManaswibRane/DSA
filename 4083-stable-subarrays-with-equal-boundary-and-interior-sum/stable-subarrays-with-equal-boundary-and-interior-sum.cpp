class Solution {
public:
typedef long long ll;
struct pair_hash {


    size_t operator()(const pair<ll, ll>& p) const {
       
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};
    long long countStableSubarrays(vector<int>& cap) {
          unordered_map<pair<ll,ll>,ll,pair_hash> mp;
          ll pre=0;
          ll ans=0;
          for(ll i=0;i<cap.size();i++){
              
               if(mp.find({cap[i],(pre-cap[i])})!=mp.end() ){
                  ans+=mp[{cap[i],(pre-cap[i])}];
        
               }
               if(i>=1 && cap[i]==0 && cap[i-1]==0){
                ans-=1;
               }
                pre+=cap[i];
               mp[{cap[i],pre}]++;
          }
          return ans;
    }
};