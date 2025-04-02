class Solution {
public:
    long long fun(int ind, int n, vector<vector<int>>& arr, vector<long long>& dp) {
        if (ind >= n) return 0;
        if (dp[ind] != -1) return dp[ind];

        long long maxi = LLONG_MIN;
        int s = arr[ind][1];

        maxi = arr[ind][0] + fun(s + ind + 1, n, arr, dp);
        return dp[ind] = max(maxi, fun(ind + 1, n, arr, dp));
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return fun(0, n, questions, dp);
    }
};
