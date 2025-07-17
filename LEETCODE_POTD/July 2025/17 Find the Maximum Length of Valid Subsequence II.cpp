class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;

        for (int val = 0; val < k; ++val) {
            vector<int> dp(k, 0); // dp[mod] = max length ending with mod
            for (int num : nums) {
                int curr = num % k;
                int need = (k + val - curr) % k;
                int prev = dp[need];
                dp[curr] = max(dp[curr], prev + 1);
                ans = max(ans, dp[curr]);
            }
        }
        return ans;
    }
};
