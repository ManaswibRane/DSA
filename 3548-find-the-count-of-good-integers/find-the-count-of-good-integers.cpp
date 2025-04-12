class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        long long ans=0;
        unordered_set<string> SET;
        int d=(n+1)/2;
        vector<int> fact(11,1);
        for(int i=1;i<11;i++){
            fact[i]=fact[i-1]*i;
        } 
        int st=pow(10,d-1),end=pow(10,d)-1;
         string rightHalf;
         string leftHalf;
   
        for(int i=st;i<=end;i++){
           leftHalf=to_string(i);
            if(n%2==0){

               rightHalf =leftHalf;
                reverse(rightHalf.begin(),rightHalf.end());
            }
            else{
                 
               rightHalf =leftHalf.substr(0,d-1);
                reverse(rightHalf.begin(),rightHalf.end());
            }
            string full=leftHalf+rightHalf;
            long long num=stoll(full);
            if(num%k==0){
                sort(full.begin(),full.end());
                cout<<full;
                SET.insert(full);
            }
        }
        for(const string & str : SET){
            vector<int> count(10,0);
            for(const char ch : str){
                count[ch-'0']++;
            }
           int total=str.length();
           int zeros = count[0];
           int nonZero=(total-zeros);
           long long permut=(nonZero*fact[total-1]);
           for(int i=0;i<10;i++){
            permut/=fact[count[i]];
           }
           ans+=permut;
        }
   return ans;
    }
};