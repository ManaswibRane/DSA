class Solution {
public:
   unordered_map<string,bool> mp;
   bool isConcat(string s,unordered_set<string> &st){
       int l=s.length();
       if(mp.find(s)!=mp.end()){
        return mp[s];
       }
       for(int i=0;i<l;i++){

             string prefix=s.substr(0,i+1);
             string suffix=s.substr(i+1);
             if( (st.find(prefix)!=st.end() && isConcat(suffix,st) ) || (st.find(prefix)!=st.end() && st.find(suffix)!=st.end())){
                return mp[s]=true;
             }
       }
       return mp[s]=false;

   }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& w) {
        int n=w.size();
        unordered_set<string> st(w.begin(),w.end());
        vector<string> ans;
        for(int i=0;i<n;i++){
                       st.erase(w[i]);
            mp.clear(); 
            if(isConcat(w[i],st)){
               ans.push_back(w[i]);
               
            }
             st.insert(w[i]); 
        }
        return ans;
    }
};