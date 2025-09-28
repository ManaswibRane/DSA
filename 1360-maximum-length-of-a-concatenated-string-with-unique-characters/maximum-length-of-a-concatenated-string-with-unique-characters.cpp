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
    int solve(vector<string>& arr,vector<int> &dp,int i,int n,unordered_set<char> mp){
           if(i>=n){
            return 0;
           }
           int take=0,notTake=notTake=solve(arr,dp,i+1,n,mp);
           if(takePoss(mp,arr[i])){
            for(char ch: arr[i]){
                mp.insert(ch);
            }
            take=arr[i].length()+solve(arr,dp,i+1,n,mp);
            
           }
           return max(take,notTake);
         
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        unordered_set<char> mp;
        return solve(arr,dp,0,n,mp);
    }
};