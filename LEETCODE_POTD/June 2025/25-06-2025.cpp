class Solution {
public:
    using ll = long long;

    ll countLessEqual(vector<int>& A, vector<int>& B, ll x) {
        int m = A.size(), n = B.size();
        ll count = 0;
        for (int i = 0; i < m; ++i) {
            if (A[i] > 0) {
                // nums2[j] <= x / A[i]
                int l = 0, r = n;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if ((ll)A[i] * B[mid] <= x)
                        l = mid + 1;
                    else
                        r = mid;
                }
                count += l;
            } else if (A[i] == 0) {
                if (x >= 0) count += n;  // all products are 0
            } else {
                // A[i] < 0, need B[j] >= ceil(x / A[i])
                int l = 0, r = n;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if ((ll)A[i] * B[mid] <= x)
                        r = mid;
                    else
                        l = mid + 1;
                }
                count += (n - l);
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll low = -1e10, high = 1e10;
        while (low < high) {
            ll mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
