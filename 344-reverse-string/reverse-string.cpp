class Solution {
public:
    void reverseString(vector<char>& s,int x=0) {
        int n=s.size();
        if(x==n/2){
            return;
        }
        swap(s[x],s[n-x-1]);
        reverseString(s,++x);
    }
};