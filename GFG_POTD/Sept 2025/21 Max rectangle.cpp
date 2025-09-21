#define vi vector<int>
class Solution {
  public:
     int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // Arrays to store the left and right boundaries for each bar
        vi left(n, -1);  // Initialize left with -1 (no smaller element on left)
        vi right(n, n);  // Initialize right with n (no smaller element on right)
        stack<int> st;    // Stack to keep indices of bars

        // Find the left smaller elements for each bar
        for (int i = 0; i < n; ++i) {
            // Pop until the top bar has height >= current bar
            while (!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            // If stack is not empty, the top is the left smaller element
            if (!st.empty())
                left[i] = st.top();
            st.push(i); // Push current index to stack
        }

        // Clear the stack for right pass
        while (!st.empty())
            st.pop();
        // Find the right smaller elements for each bar
        for (int i = n - 1; i >= 0; --i) {
            // Pop until the top bar has height >= current bar
            while (!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            // If stack is not empty, the top is the right smaller element
            if (!st.empty())
                right[i] = st.top();
            st.push(i); // Push current index to stack
        }

        int ans = 0;
        // Calculate the maximum area for each bar
        for (int i = 0; i < n; ++i) {
            // Width = (right boundary - left boundary - 1)
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }

        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        // Calculate the maximum area for the first row
        int ans = largestRectangleArea(mat[0]);
        for(int i = 1; i<n; ++i){
            for(int j = 0; j<m; ++j){
                // Update the row to represent histogram heights
                if(mat[i][j] == 1)
                    mat[i][j] = mat[i-1][j] + 1;
                else 
                    mat[i][j] = 0; // Reset if base is 0
            }
            // Compute the largest rectangle area for the current row histogram
            ans = max(ans, largestRectangleArea(mat[i]));
        }
        
        return ans;
    }
};
