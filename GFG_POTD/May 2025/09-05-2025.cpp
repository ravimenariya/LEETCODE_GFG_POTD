class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMax(string& s, int k) {
        // Base case: If no swaps are left, return the current number
        if (k == 0) {
            return s;
        }

        int    n   = s.size();
        string ans = s;

        // Traverse all pairs of characters in the string
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // Swap only if it increases the value at position i
                if (s[i] < s[j]) {
                    // Perform the swap
                    swap(s[i], s[j]);

                    // Recursive call with one less allowed swap
                    ans = max(ans, findMax(s, k - 1));

                    // Backtrack to the original state
                    swap(s[i], s[j]);
                }
            }
        }

        return ans;
    }
    // Wrapper function to call recursive utility
    string findMaximumNum(string s, int k) {
        return findMax(s, k);
    }
};
