class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int n=m.size();
        int col=m[0].size(); 
        vector<int> ans;
        int top=0,bot=n-1,l=0,r=col-1,dir=0;
        while(top<=bot && l<=r){
           if(dir==0){
            for(int i=l;i<=r;i++){
               ans.push_back(m[top][i]);
            }
        
            top++;

           }
            if(dir==1){
            for(int i=top;i<=bot;i++){
               ans.push_back(m[i][r]);
            }
        r--;
           }
            if(dir==2){
            for(int i=r;i>=l;i--){
               ans.push_back(m[bot][i]);
            }
            bot--;
           }
            if(dir==3){
            for(int i=bot;i>=top;i--){
               ans.push_back(m[i][l]);
            }
           l++ ;
           }
           dir++;
           if(dir==4){
            dir=0;
           }
        }
        return ans;
    }
};