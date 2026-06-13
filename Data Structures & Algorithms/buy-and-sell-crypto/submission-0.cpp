class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b =prices[0],s=prices[0], profit=0;
        for(int i =1;i<prices.size();i++){
              if(prices[i]<b){
                b=s=prices[i];
              } else if (prices[i] > s){
                s=prices[i];
                profit=max(profit, s-b);
              }

        }
        return profit;
    }
};
