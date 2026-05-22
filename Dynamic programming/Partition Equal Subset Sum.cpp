class Solution {
public:
// 0/1 KNAPSACK TYPE ->
    bool canPartition(vector<int>& nums) {
        // if there is two equal subsets to be made to make their sums equal then s1 + s2 = total -> 2*s1 = total.
         int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        // if sum cant be even the obviously it cant be divided into two equal subsets.
        if(sum%2 != 0){
            return false;
        }
        // target for oe subset and we only have to see if one of the subsets satisfies target->
        int target = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1));
        // initialization -> if no elements then none left to satify the target so false->
        for(int i = 1; i<=target; i++){
            dp[0][i] = false;
        }
                
         // initialization -> if no target and we have the option to choose none hence all true->

        for(int i = 0; i<=n; i++){
            dp[i][0] = true;
        }
        // if current number is greater than the current target (j) then just ignore it.
        // if not then two options -> 1) either ignore it or 2) take it .
        for(int i = 1; i<=n; i++){
            for(int j = 1; j <= target; j++){
                if(nums[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][target];
    }
};
