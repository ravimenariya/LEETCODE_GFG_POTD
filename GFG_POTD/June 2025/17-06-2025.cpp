class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> prefixSum(n);
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        int ans = INT_MAX,prev = 0; 

        for (int i = 0; i < n; i++) {
            if (i != 0)         prev = prefixSum[i - 1];
            int pos = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
            int total = pos > 0 ? prefixSum[n - 1] - prefixSum[pos - 1] : 0;
            int allowed = (n - pos) * (arr[i] + k);
            int extraCoins = total + prev - allowed;
            ans = min(ans, extraCoins);
        }
        return ans;
    }
};
