class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum=0;
        for(int pile: piles){
            sum+=pile;
            pq.push(pile);
        }
        while(k-- ){
            int x=pq.top();
            sum-=x/2;
            pq.pop();
            pq.push(x-x/2);
        }
        return sum;
    }
};