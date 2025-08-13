class Solution {
public:
    bool isPowerOfThree(int n) {
    // The largest power of 3 that fits in a integer is :3^19=1162261467
    //So, any number n that is a power of 3 must divide 1162261467 exactly.
        return n > 0 && 1162261467 % n == 0;
    }
};
