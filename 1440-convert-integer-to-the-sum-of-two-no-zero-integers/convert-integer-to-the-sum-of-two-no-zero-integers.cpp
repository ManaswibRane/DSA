class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i=1;i<n;i++){
                
                int x=i;
                int y=n-i;

        string str1=to_string(x);
        sort(str1.begin(),str1.end());
        string str2=to_string(y);
        sort(str2.begin(),str2.end());
           if(str1[0]!='0' && str2[0]!='0'){
                 return {x,y};
               }

        }
        return {-1,-1};
       
    }
};