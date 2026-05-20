class Solution {
public:
    // using dp ->
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        // created a dp 1D array to store the values of the maximum sum till that iteration without taking the consecutive ones.
        vector<int> dp(n+1);
        // initialize dp[1] and dp[2] for the first and the second elements.
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);
        // loop from the 3rd element ->
        for(int i = 3; i<=n; i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        // return the dp[n] which is the required answer.
        return dp[n];
    }
    // for case one [1,2,3,1] ->
    // dp[] = {1,2,4,4} -> ans = dp[4] = 4.
};
