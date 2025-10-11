class Solution {
    int solve(Node* root,int&ans)
    {
        if(!root)   return 0;
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        int m1=max({root->data,root->data+left,root->data+right});
    ans=max({ans,m1,root->data+left+right});
        return m1;
    }
  public:
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};
