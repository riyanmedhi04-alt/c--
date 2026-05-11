class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        long long x = nums[0];
        // taking the xor of all the values in the array.
        for(int i = 1; i<n; i++){
            x ^= nums[i];
        }
        long long q;
        for(int bit = 0; bit<32; bit++){
            // finding the rightmost set bit in the xor and then breaking . storing the value to q.
            if(x & (1<<bit)){
                q = x & (1<<bit);
                break;
            }
        }
        // creating two different variables for xors.
        long long x1 = 0, x2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] & q){
                // this xor for those integers having set bit at the position value of q.
                x1 ^= nums[i];
            }else{
                // this xor for those integers having not set bit at the position of q.
                x2 ^= nums[i];
            }
        }
        // we get the two unique numbers as the other numbers appearing two times in both the groups get cancelled anyway. 
        v.push_back(x1);
        v.push_back(x2);
        return v;

    }
};
