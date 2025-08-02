class Solution {
public:
   typedef pair<string,int> P;
    vector<string> topKFrequent(vector<string>& words, int k) {
         vector<P> vec;
         unordered_map<string,int> mp;
         for(string s : words){
              mp[s]++;
         } 
         for(auto it : mp){
            vec.push_back({it.first,it.second});
         }
         auto lambda=[&](P p1,P p2){
         if(p1.second == p2.second){
                  return p1.first < p2.first;
         }
                 return p1.second > p2.second;
         };
         sort(vec.begin(),vec.end(),lambda);
         vector<string> ans;
         for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
         }
         return ans;
    }
};