class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size(), n = m / 3;
        long long lsum = 0, rsum = 0;
        vector<long long> v_l(m, -1), v_r(m, -1);
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;

        for (int i = 0; i < n; i++) {
            lsum += nums[i];
            rsum += nums[m - 1 - i];
            pq1.push(nums[i]);
            pq2.push(nums[m - 1 - i]);
        }
        v_l[n-1]=lsum;
        for (int i = n; i < m - n; i++) {
            if (nums[i] < pq1.top()) {
                lsum -= pq1.top();
                pq1.pop();
                lsum += nums[i];
                pq1.push(nums[i]);
            }
            v_l[i] = lsum;
        }
        for (int i = m - n - 1; i >= (n - 1); i--) {
            v_r[i] = rsum;
            if (nums[i] > pq2.top()) {
                rsum -= pq2.top();
                pq2.pop();
                rsum += nums[i];
                pq2.push(nums[i]);
            }
        }

        long long  ans = LLONG_MAX;
        for (int i = 0; i < m; i++) {
            if (v_l[i] == -1)    continue;
            ans = min(ans, v_l[i] - v_r[i]);
        }
        return ans;
    }
};
