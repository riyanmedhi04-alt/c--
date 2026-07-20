class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0){
            return 1;
        }
        vector<unsigned int> dp(amount +1);
        dp[0] = 1;
        // the idea is for a "coin" how many ways or combinations are there for deriving ith amount!!
        // dp[i] -> the combinations for making up i from the coin in coins which are <= i
        for(int coin : coins){
            for(int i = 1; i<=amount; i++){
                if(coin<=i){
                    dp[i] += dp[i-coin];
                }
            }
        }
        return dp[amount];
    }
};
