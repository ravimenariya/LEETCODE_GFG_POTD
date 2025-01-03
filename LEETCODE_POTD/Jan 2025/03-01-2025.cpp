class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> v1(n, 0); 
        vector<long long> v2(n, 0); 

        v1[0] = nums[0];
        for (int i = 1; i < n; i++) {
            v1[i] = v1[i - 1] + (long long)nums[i];
        }

        v2[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            v2[i] = v2[i + 1] + (long long)nums[i];
        }


        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v1[i] >= v2[i + 1]) {
                ans++;
            }
        }

        return ans;
    }
};
