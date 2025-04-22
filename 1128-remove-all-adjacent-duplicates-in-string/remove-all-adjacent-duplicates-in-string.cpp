class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            cout<<s[i]<<"\t";
           if(st.empty()){
            st.push(s[i]);
           }
          else if(st.top()==s[i]  ){
            st.pop();
           }
          else{
             st.push(s[i]);
          }
          if(!st.empty()){
             cout<<st.top()<<endl;
           }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};