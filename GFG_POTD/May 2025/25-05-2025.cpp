class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<long long> st;  // Store squares of all elements

        // Precompute squares of all elements
        for (int &x : arr) {
            st.insert(1LL * x * x);  // Store as long long to avoid overflow
        }

        int n = arr.size();

        // Try all pairs (a, b)
        for (int i = 0; i < n; i++) {
            int a = arr[i];
            for (int j = i + 1; j < n; j++) {
                int b = arr[j];

                long long sumSq = 1LL * a * a + 1LL * b * b;

                // Check if c^2 = a^2 + b^2 exists in the set
                if (st.count(sumSq)) {
                    return true;  // Triplet found
                }
            }
        }

        return false;  // No triplet found
    }
};
