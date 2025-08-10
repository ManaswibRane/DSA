class Solution {
public:
    bool reorderedPowerOf2(int n) {
            unordered_set<string> mp;
            if(n==1) return true;
            for(int i=2;i<pow(10,9);i*=2){
                string s=to_string(i);
                sort(s.begin(),s.end());
                mp.insert(s);
            }
            string s=to_string(n);
            sort(s.begin(),s.end());
            if(mp.find(s)!=mp.end()){
                return true;
            }
            return false;
    }
};