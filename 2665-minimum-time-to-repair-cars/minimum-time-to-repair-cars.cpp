class Solution {
public:
     typedef long long L;
    bool solve(vector<int>& ranks, int cars,L mid){
        L c=0;
        for(int i=0;i<ranks.size();i++){
            c+=sqrt(mid/ranks[i]);
        }
        return c>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        L maxRank=*max_element(ranks.begin(),ranks.end());
        L st=0,end=maxRank*cars*cars*1LL,ans;
        while(st<=end){
            L mid=st+(end-st)/2;
           if(solve(ranks,cars,mid)){
            ans=mid;
            end=mid-1;
           }
           else{
            st=mid+1;
           }
        }
        return ans;
    }
};