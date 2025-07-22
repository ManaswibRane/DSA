class Solution {
public:
bool check(int mid,vector<int>& piles, int h){
    long long hrs=0;
    for(int banana:piles){
        hrs+=banana/mid;
        if(banana%mid!=0){
            hrs++;
        }

    }
    return hrs<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int st=1;
        int end=*max_element(piles.begin(),piles.end());
        while(st<=end){
            int mid=st+(end-st)/2;
            if(check(mid,piles,h)){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return end+1;
    }
};