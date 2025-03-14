
// Problem -> https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
       int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else {
                    int pick = 0;
                    if (wt[i - 1] <= j)
                        pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                    int notPick = dp[i - 1][j];
                    dp[i][j] = max(pick, notPick);
                }
            }
        }
        return dp[n][W];
    }
};
