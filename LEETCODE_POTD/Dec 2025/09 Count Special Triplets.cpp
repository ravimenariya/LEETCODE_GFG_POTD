class Solution {
    static const int MOD = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size(),MAXV = 100000; 
        vector<int> suf(MAXV + 1, 0), pre(MAXV + 1, 0);
        for (int x : nums)    suf[x]++;

        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            suf[nums[j]]--;
            int d = nums[j] * 2;
            if (d <= MAXV)    ans += 1LL * pre[d] * suf[d];
            pre[nums[j]]++;
        }

        return 
        (int)(ans % MOD);
    }
};
