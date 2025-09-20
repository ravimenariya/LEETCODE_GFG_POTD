class Solution {
public:
    static int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            int curr = (i == n) ? INT_MAX : arr[i];
            while (!st.empty() && arr[st.top()] < curr) {
                int j = st.top();
                st.pop();
                int prevIndex = st.empty() ? -1 : st.top();
                int len = i - 1 - prevIndex;
                if (arr[j] <= len) {
                    res = max(res, len);
                }
            }
            if (i < n) {
                st.push(i);
            }
        }
        return res;
    }
};
