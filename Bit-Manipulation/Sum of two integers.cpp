class Solution {
public:
    int getSum(int a, int b) {
        // loop until carry becomes 0.
        while(b != 0){
            // carry happens only when both bits are 1 i.e. AND ... since it effects the next bit hence left shift it by 1.
            int carry = (a&b)<<1;
            // sum without carry = XOR.
            // set a to the sum and b to carry.
            a = a^b;
            b = carry;
        }
        // return final a.
        return a;
    }
};
