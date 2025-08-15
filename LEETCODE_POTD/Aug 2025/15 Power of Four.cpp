class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check: positive, power of two, and bit in correct position.Among powers of two, powers of four have their single 1 bit in an odd position (1-based index from right).
        return (n > 0) &&
               ((n & (n - 1)) == 0) &&
               ((n & 0x55555555) != 0);
    }
};
