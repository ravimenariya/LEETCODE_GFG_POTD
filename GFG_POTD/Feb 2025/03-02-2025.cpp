
// Problem ->  https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

class Solution {
    void solve(Node* node,int curr,int&ans)
    {
        if(!node)   return;
        ans=max(ans,curr);
        solve(node->left,curr+1,ans);
        solve(node->right,curr+1,ans);
    }
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        int ans=0;
        solve(node,0,ans);
        return ans;
    }
};
