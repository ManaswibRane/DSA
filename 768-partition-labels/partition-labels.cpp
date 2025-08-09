class Solution {
public:
    vector<int> partitionLabels(string s) {
    
        vector<int> index(26,0);
        for(int i=0;i<s.length();i++){
            char ch=s[i];
              index[ch-'a']=i;
             
        }
       
        int i=0;
        vector<int> ans;
        int end;
        while(i<s.length()){
              char ch=s[i];
                 end=index[ch-'a'];
                 for(int j=i;j<=end;j++){
                     end=max(index[s[j]-'a'],end);
                 }
                ans.push_back(end-i+1);
                i=end+1;

        }
             return ans;
    }
};