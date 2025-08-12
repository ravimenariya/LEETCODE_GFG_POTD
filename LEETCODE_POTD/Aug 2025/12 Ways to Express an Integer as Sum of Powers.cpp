class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int>nums;
        int i=2,m=1,mod=1e9 + 7;
        while(m<=n){
            nums.push_back(m);
            m=pow(i,x);
            i++;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  

        for (int num : nums) {
            for (int t = n; t >= num; --t) {
                dp[t] = (dp[t] + dp[t - num])%mod;
            }
        }
        return dp[n];
    }
};
