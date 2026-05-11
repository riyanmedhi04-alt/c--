class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // the ans we are building , set it to 000..000
        for(int bit = 0; bit<32; bit++){
            // for loop for all the 32 bits we are counting to be set bits.
            int cnt = 0;
            // count counter.
            for(int num : nums){
                // for each number in nums we iterate and see if that particular bit in that number is set or not.
                // if its set then increase the cnt counter .
                // look if the count of sert bits in the numbers are a multiple of 3 then obviously the bit is the replica of the bits set in the 3 appearing numbers and is NOT in the unique number.
                if(num & (1<<bit)){
                    cnt++;
                }
                // BUT if the cnt if not a multiple of 3 then it is set in the unique number and hence we will also make it set in the ans we are building.
            }
            if(cnt%3){
                ans |= (1<<bit);
              // building the ans with OR and left shift .
            }
        }
        return ans;
    }
};
