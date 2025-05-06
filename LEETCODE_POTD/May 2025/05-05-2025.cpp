class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        const int MOD = 1000000007;
        std::vector<int> dp(n + 1, 0);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++) {
            dp[i] = (2LL * dp[i - 1] % MOD + dp[i - 3]) % MOD;
        }

        return dp[n];
    }
};
