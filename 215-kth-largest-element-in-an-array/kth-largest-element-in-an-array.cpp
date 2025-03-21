class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto num: nums){
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
        if(pq.size()==0) return -1;
        return pq.top();
    }
};