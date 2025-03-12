class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
                 unordered_map<char,int> count;
         vector<int> ans;
         int t=txt.length(),p=pat.length();
        for(int i=0;i<p;i++){
            count[pat[i]]++;
        }
         int i=0,j=0;
         while(j<t){
             count[txt[j]]--;
             if( count[txt[j]]==0){
                 count.erase(txt[j]);
             }
             
             if(j-i+1==p){
                if(count.empty()) ans.push_back(i);
               
                 count[txt[i]]++;
                if (count[txt[i]] == 0) count.erase(txt[i]);
                 i++;
             }
             j++;
         }
         return ans;
    }
};