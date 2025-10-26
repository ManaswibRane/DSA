class Solution {
public:

    int totalMoney(int n) {
        int ans=0;
        int st=1,it=1;
        for(int i=1;i<=n;i++){
            ans+=st;
            st++;
            if(i%7==0){
                it++;
                st=it;
            }
        }
        return ans;
    }
};