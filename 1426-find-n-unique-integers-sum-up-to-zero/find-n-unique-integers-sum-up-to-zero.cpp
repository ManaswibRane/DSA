class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> vec;
        if(n==1) return {0};
        if(n%2==0){
            int i=1;
            while(n>0){
              vec.push_back(i);
              vec.push_back(-i);
              n-=2;
              i++;
            }
        }

        else{
           vec.push_back(-3); 
           vec.push_back(1);   
           vec.push_back(2);
           n-=3;
             int i=4;
            while(n>0){
              vec.push_back(i);
              vec.push_back(-i);
              n-=2;
              i++;
            }
        }
        return vec;
    }
};