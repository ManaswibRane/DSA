class Solution {
public:
    int gcdOfOddEvenSums(int n) {
           int i=1;
           int even=0,odd=0;
           int e=2,o=1;
           while(i<=n){
                
                    even+=e;
                    e+=2;

                
                 
                  
                    odd+=o;
                    o+=2;

                
                 i++;
           }
           while(even!=odd){
            if(even>odd){
                even-=odd;
            }
            else{
                odd-=even;
            }
           }
           return even;
    }
};