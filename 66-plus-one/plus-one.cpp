class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int ct=1;
        for(int i=n-1;i>=0 && ct>0;i--){
               if(digits[i]!=9){
                  digits[i]+=1;
                  break;
               }
               else{
                 digits[i]=0;
                  if((i==0)){
                   
                    digits.insert(digits.begin(),1);
                  }

               }
        }
        return digits;
    }
};