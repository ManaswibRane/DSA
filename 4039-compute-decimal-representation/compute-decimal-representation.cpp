class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long prod=1;
        while(n>0){
            int k=n%10;
            if(k!=0) ans.push_back(k*(int)prod);
            prod*=10;
            n/=10;
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};