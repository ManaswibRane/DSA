class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int sum=0,n=colors.size();
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }

        int j=1,N=n+k-1,i=0;
        while(j<N){
            if(colors[j]==colors[j-1]){
                i=j;
                j++;
                continue;
            }
            if(j-i+1==k){
                sum++;
                i++;

            }
            j++;
        }
        return sum;
    }
};