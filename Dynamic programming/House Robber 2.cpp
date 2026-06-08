class Solution {
public:
    // using dp ->
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
      // the difference between house robber 1 & 2 is that in 2 , i created a dp1 which basically stores the maximum money robbed ending with i if we dont count the first house as last and first house are always neighbours and that the only DIFFERENCE->
      // so while storing the last dp[n] only store max of dp[i-1] (where last house is excluded) & dp1[i-2] + nums[i-2] (where last house is included since here dp1 so safe) & dp1[i-1] (last house is exclude , i.e no first and last house included).
        vector<int> dp(n+1), dp1(n+1);
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);
        dp1[2] = nums[1];
        dp1[1] = 0;
        for(int i = 3; i<=n; i++){
            if(i == n){
                dp[i] = max(dp[i-1], max((dp1[i-2]+nums[i-1]), dp1[i-1]));
                continue;
            }
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};
