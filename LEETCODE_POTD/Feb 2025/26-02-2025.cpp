
// problem ->  https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/submissions/1556387866/?envType=daily-question&envId=2025-02-26

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int currMax = 0, currMin = 0;

        for (int num : nums) {
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);
            
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);
        }

        return max(maxSum, abs(minSum));
    }
};
