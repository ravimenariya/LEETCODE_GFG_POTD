
// Problem ->  https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int ans=0;
    int diameter(Node* root) {
        height(root);
        return ans-1;
    }
    
    int height(Node* root)
    {
        if(!root)   return 0;
        int h1=height(root->left);
        int h2=height(root->right);
        ans=max(ans,1+h1+h2);
        return 1+max(h1,h2);
    }
};
