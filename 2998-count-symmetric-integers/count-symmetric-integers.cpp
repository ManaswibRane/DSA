class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
         int ans=0;
        for(int i=low ;i<=high;i++){
                     string str=to_string(i);
                     int len=str.length();
                     if(len%2!=0){
                        continue;
                     }
                     int preSum=0,postSum=0;
                     for(int j=0;j<len/2;j++){
                       preSum+=(str[j]-'0');
                     }
                        for(int j=len/2;j<len;j++){
                       postSum+=(str[j]-'0');
                     }
                     if(preSum==postSum){
                        ans++;
                     }
            }


                return ans;
    }
};