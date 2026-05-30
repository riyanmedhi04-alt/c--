class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
          // here basically nums[(i+1)%n] checks for element in its rotated position->
            if(nums[i] > nums[(i+1)%n]){
                cnt++;
            }
        }
        return cnt<=1;    
    }
};
