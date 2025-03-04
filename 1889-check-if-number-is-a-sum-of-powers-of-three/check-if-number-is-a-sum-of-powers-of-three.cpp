class Solution {
public:
    bool check(int& n){
      
         if(n%3==2) return false;
         if((n==0) || n==1) return true;
         n/=3;
       return check(n);
       
    }
    bool checkPowersOfThree(int n) {
        if(n<0) return false;
        if(check(n)){
            return true;
        }
        return false;
    }
};