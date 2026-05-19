class Solution {
public:
// using binary search ->
    int binSearch(vector<int> &lis, int l , int r, int x){
        while(r>l){
            int mid = (l+r)/2;
            if(lis[mid] >= x){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n);
        lis[0] = nums[0];
        int len = 1;
        for(int i = 1; i<n; i++){
            if(nums[i] > lis[len-1]){
                lis[len] = nums[i];
                len++;
            }else{
                int c = binSearch(lis,0, len-1, nums[i]);
                lis[c] = nums[i];
            }
        }
        return len;
    }
};
