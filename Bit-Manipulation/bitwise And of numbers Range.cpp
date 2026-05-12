class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // initialize ans = 00..0000.
        int ans = 0;
        for(int bit = 0; bit<32; bit++){
            // checking left and right bits are set or not at that particular bit posn where we are iterating.
            int p = left & (1<<bit);
            int q = right & (1<<bit);
            // if taht particular bit is not set in left or right or If number of integers in taht range is greater than the value in that particular bit then bit = 0 in ans. ELSE bit = 1 in ans.
            if(p == 0 || q == 0 || right-left+1 > pow(2,bit)){
                ans |= 0<<bit;
            }else{
                ans |= 1<<bit;
            }
        }
        return ans;
    }
};
