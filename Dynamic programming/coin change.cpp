class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        // transition from 1->amount ... dp[i] -> min no. of denominations req for making up i
        for(int i = 1; i<=amount; i++){
            for(int coin : coins){
                if(coin<=i){
                    dp[i] = min(dp[i], dp[i-coin] +1);
                }
            }
        }
        if(dp[amount] == 1e9){
            return -1;
        }else{
            return dp[amount];
        }
    }
};
