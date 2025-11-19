class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int bits = 0;
        for (auto& n : nums) {
            if (n % original != 0) continue;
            n /= original;
            if ((n & (n - 1)) == 0)
                bits |= n;
        }
        bits++;
        return original * (bits & -bits);
    }
};
