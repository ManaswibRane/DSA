class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ingre, vector<string>& supplies) {
        vector<string> ans;
        int rs=rec.size();
        int is=ingre.size();
        int s=supplies.size();
        int count=rs;
        unordered_set<string> supp;
        vector<bool> done(count,false);
       
        for(int i=0;i<s;i++){
           
             supp.insert(supplies[i]);
        }
        unordered_map<string,vector<string>> unprep;
         while(count--){
        for(int i=0;i<rs;i++){
             if(done[i]) continue;
            bool alling=true;
            for(int j=0;j<ingre[i].size();j++){
                if (supp.find(ingre[i][j])==supp.end()){
                    alling=false;
                   unprep[rec[i]].push_back(ingre[i][j]);

                } 
               
            }
            if(alling){
                    ans.push_back(rec[i]);
                    supp.insert(rec[i]);
                    done[i]=true;
                }
        }
    }
     return ans;
    }
};