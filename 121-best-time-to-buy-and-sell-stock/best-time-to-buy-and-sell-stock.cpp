class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size(),maxProfit=-1;
    vector<int> bestPrice(n);
    int bestBuy=INT_MAX;
     for(int i=0;i<n;i++){
              bestPrice[i]=bestBuy;
              bestBuy=min(bestBuy,prices[i]);
     
       }
       for(int i=1;i<n;i++){
              int x=prices[i];
              maxProfit=max(maxProfit,(x-bestPrice[i]));
       }
       return maxProfit>0 ? maxProfit:0;

    }
};