class Solution {
    int ans=-1;
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        if(root->data<=k)   
        {
            ans= root->data;
            if(root->right) findMaxFork(root->right,k);
        }
        else if(root->left)  findMaxFork(root->left,k);
        return ans;
    }
};
