class Solution {
public:
    int reverseBits(int n) {
        // initializing ans = 00....000.
        int ans = 0;
        for(int bit = 0; bit<32; bit++){
            // creating a for loop for each of 32 bits.
            if(n & (1<<bit)){
                // searching if there is a bit set at that bi position where we are iterating.
                ans |= (1<<(31-bit));
                // constructing the ans with setting the bit into teh reversed(31 - bit) position.
            }
        }
        return ans;
    }
};
