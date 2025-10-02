class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int chgCt=0;
        int ans=0;
        ans+=numBottles;
        while(numBottles>=numExchange){
            numBottles-=numExchange++;
            chgCt++;

        }
        ans+=chgCt;
        if((chgCt+numBottles)>=numExchange){
            ans++;
        }
        return ans;
 
    }
};