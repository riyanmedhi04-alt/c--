class Solution {
public:
// using dynamic programming ->
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n);
        lis[0] = 1;
        int res = lis[0];
        for(int i = 0; i<n; i++){
            lis[i] = 1;
            for(int j = 0; j<i; j++){
                if(nums[i] > nums[j]){
                    lis[i] = max(lis[i], lis[j]+1);
                }
            }
            res = max(res, lis[i]);
        }
        return res;

    }
};
