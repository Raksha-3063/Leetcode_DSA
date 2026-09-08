class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int  minPrice = prices[0];
       int max_profit = 0;

       for(int i=0;i<prices.size();i++){
        minPrice = min(minPrice,prices[i]);

        int profit = prices[i]-minPrice;
        max_profit = max(max_profit,profit);
       }
       return max_profit;
    }
};