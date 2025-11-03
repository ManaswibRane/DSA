class Solution {
public:
// int solve(string colors, vector<int>& needed,vector<vector<int>>&dp,int i,int n,char ch){
//        if (i==n){
//         return 0;
//        }
//        if(ch!='$'){
//              if(dp[i][ch-'a']!=-1){
//                 return dp[i][ch-'a'];
//         }
//        }
      
//        int take=INT_MAX;
//        int nottake=INT_MAX;
//        if(ch!=colors[i]){
//         take=solve(colors,needed,dp,i+1,n,colors[i]);
//        }
//        nottake=solve(colors,needed,dp,i+1,n,ch);
//        if(nottake!=INT_MAX){
//         nottake+=needed[i];
//        }
//        return min(take,nottake);

// }
    int minCost(string c, vector<int>& needed) {
        int i=0;
        int cost=0;
        int n=needed.size();
        while(i<n){
            int sum=needed[i];
            int mn=needed[i];
            int j=i+1;
            int ct=1;
            while(j<n && c[j]==c[i]){
               
                mn=max(needed[j],mn);
                sum+=needed[j];
                j++;
                ct++;
            }
            if(ct>1){
                cost+=sum;
                cost-=mn;
            }

           i=j;
           if(i<n) sum=needed[i];
           ct=1;
           

        }
        return cost;

    }

};