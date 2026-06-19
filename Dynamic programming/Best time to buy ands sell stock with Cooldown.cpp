class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n+1), rest(n+1), sell(n+1);
        // maximum profit at ith day given -> hold[i] -> we hold the stock, sell[i] -> sold the stock, rest[i] -> we didnt bought or sold the stock (cooldown day)
        hold[0] = -prices[0]; // since we have no choice but to only buy at day 0 so the profit is -ve!!
        rest[0] = 0;
        sell[0] = 0;
        for(int i = 1; i<n; i++){
            hold[i] = max(hold[i-1], rest[i-1] - prices[i]); // we holded the current stock and didnt bought the stock at ith day OR we buyed a fresh new stock at ith day.
            sell[i] = prices[i] + hold[i-1]; // we sold at the curr day and profit is basically the holded stock till yesterday + price of the stock today
            rest[i] = max(rest[i-1], sell[i-1]); // resting yesterday and also today too.
        }
        return max(sell[n-1],rest[n-1]);
        
    }
};
