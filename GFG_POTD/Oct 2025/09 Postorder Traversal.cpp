class Solution {
    void solve(Node*root,vector<int>&ans)
    {
        if(root->left)  solve(root->left,ans);
        if(root->right) solve(root->right,ans);
        ans.push_back(root->data);
    }
  public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};
