
// Problem ->  https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2 != 0) return false; // If sum is odd, cannot partition
        
        int target = sum / 2;
        int n = arr.size();

        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

        // Base Case: 0 sum is always possible
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        // DP Table Filling
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = dp[i-1][j]; // Exclude current element
                if (j >= arr[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]]; // Include current element
                }
            }
        }

        return dp[n][target]; // Answer is in last cell
    }
};
