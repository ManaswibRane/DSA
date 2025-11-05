class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> m1;
        map<char, int> m2;
        vector<int> a;
        for(int i=0;i<p.size();i++){
            m1[p[i]]++;
        }
        for(int i=0;i<p.size();i++){
            m2[s[i]]++;
        }
        if(m1==m2){
            a.push_back(0);
        }
        for(int i=p.size();i<s.size();i++){
            m2[s[i]]++;
            m2[s[i-p.size()]]--;
            if(m2[s[i - p.size()]] == 0)
                m2.erase(s[i - p.size()]);
            if(m1==m2){
                a.push_back(i-p.size()+1);
                cout<<"i "<<i<<endl;
            }

        }
        return a;


    }
};