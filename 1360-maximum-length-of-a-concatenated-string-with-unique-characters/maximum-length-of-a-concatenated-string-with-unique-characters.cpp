class Solution {
public:
bool takePoss(unordered_set<char>& mp,string t){
    sort(t.begin(),t.end());
    for(int i=1;i<t.length();i++){
        if(t[i]==t[i-1]){
            return false;
        }
    }
   for(char ch : t){
    if(mp.find(ch)!=mp.end()){
        return false;
    }
   }
   return true;
}
    int solve(vector<string>& arr,vector<int> &dp,int i,int n,unordered_set<char> mp,string s,unordered_map<string,int> &mp2){
           if(i>=n){
            return 0;
           }
           if(mp2.find(s)!=mp2.end()){
            return mp2[s];
           }
           int take=0,notTake=notTake=solve(arr,dp,i+1,n,mp,s,mp2);
           if(takePoss(mp,arr[i])){
            for(char ch: arr[i]){
                mp.insert(ch);
            }
            take=arr[i].length()+solve(arr,dp,i+1,n,mp,s+arr[i],mp2);
            
           }
           return mp2[s]=max(take,notTake);
         
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        string s="";
        unordered_set<char> mp;
        unordered_map<string,int> mp2;
        return solve(arr,dp,0,n,mp,s,mp2);
    }
};