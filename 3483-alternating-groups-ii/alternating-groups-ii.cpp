class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int sum=0,n=colors.size();
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }

        int N=n+k-1,i=1,l=1;
       while(i<N){
           if(colors[i]!=colors[i-1]){
               l++;
               if(l>=k) sum++;
           }
           else{
            l=1;
           }
           i++;
       }
        return sum;
    }
};