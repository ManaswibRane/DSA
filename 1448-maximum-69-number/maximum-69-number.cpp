class Solution {
public:
    int maximum69Number (int num) {

        string s=to_string(num);
        // for(int i=s.length()-1;i>=0;i--){
        //     if(s[i]=='9'){
        //         cout<<i;
        //         s[i]='6';
        //         break;
        //     }
        
        // }
          for(int i=0;i<s.length();i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        
        }
        int num2=stoi(s);
        
        return (max(num,num2));
            }
};