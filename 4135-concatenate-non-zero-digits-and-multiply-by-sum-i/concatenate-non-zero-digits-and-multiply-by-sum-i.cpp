class Solution {
public:
void revnum(int &n){
   int num=0;
   while(n>0){
            int k=n%10;
         
            if(k!=0) num=num*10+k;
            n=n/10;
        }
        n=num;
}
    long long sumAndMultiply(int n) {
        int sumofdigi=0,num=0;
        while(n>0){
            int k=n%10;
            sumofdigi+=k;
            if(k!=0) num=num*10+k;
            n=n/10;
        }
        revnum(num);
        return 1LL*num*sumofdigi;
    }
};