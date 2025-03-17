
// Problem -> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
public:
    bool subsetSumHelper(vector<int>& arr, int idx, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (idx == 0) return arr[0] == sum;
        if (dp[idx][sum] != -1) return dp[idx][sum];

        bool notTake = subsetSumHelper(arr, idx - 1, sum, dp);
        bool take = false;
        if (arr[idx] <= sum)
            take = subsetSumHelper(arr, idx - 1, sum - arr[idx], dp);

        return dp[idx][sum] = (take || notTake);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return subsetSumHelper(arr, n - 1, sum, dp);
    }
};
