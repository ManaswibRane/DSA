class Solution {
public:
    int lengthOfLastWord(string s) {
      
       int idx= s.find_last_not_of(' ');
        s.erase(idx+1,s.length());
       
       idx= s.find_last_of(' ');
       if(idx==string::npos){
        return s.length();
       }
       return s.length()-idx-1;
   
  }
   
};