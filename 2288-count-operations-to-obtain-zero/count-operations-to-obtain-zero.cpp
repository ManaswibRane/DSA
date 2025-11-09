class Solution {
public:
int solve(int n1,int n2){
    if(n1==0 || n2==0){
        return 0;
    }
    if(n1>n2){
        return 1+solve(n1-n2,n2);
    }
    return 1+solve(n1,n2-n1);
}
    int countOperations(int num1, int num2) {
       return solve(num1,num2);
    }
};