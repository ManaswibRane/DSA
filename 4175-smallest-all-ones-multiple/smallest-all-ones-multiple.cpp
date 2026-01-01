class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k==2 || k==5) return -1;

        int rem=1%k;
        int len=1;
        vector<int> seen(k,false);
        while(!seen[rem]){
            if(rem==0) return len;
            seen[rem]=true;
            rem=(rem*10+1)%k;
            len++;

        }
        return -1;
    }
};