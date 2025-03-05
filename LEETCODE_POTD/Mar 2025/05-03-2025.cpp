
// Problem -> https://leetcode.com/problems/count-total-number-of-colored-cells/?envType=daily-question&envId=2025-03-05

class Solution {
public:
    long long coloredCells(int n) {
        return 2*(pow(n-1,2)+n)-1;
    }
};
