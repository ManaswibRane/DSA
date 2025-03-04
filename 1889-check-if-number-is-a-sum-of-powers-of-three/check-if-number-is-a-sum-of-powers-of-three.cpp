class Solution {
public:
  
    bool checkPowersOfThree(int n) {
        if(n<0) return false;
         while(n>0){
            int k=n%3;
            if(k==2) return false;
            n/=3;
         }
        return true;
    }
};