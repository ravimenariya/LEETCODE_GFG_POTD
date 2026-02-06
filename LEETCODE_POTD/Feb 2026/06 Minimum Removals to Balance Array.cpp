class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            long long limit = (long long)nums[i] * k;
            auto p = upper_bound(nums.begin(), nums.end(), limit);
            int count = i + (nums.end() - p);
            ans = min(ans, count);
        }
        return ans;
    }
};
