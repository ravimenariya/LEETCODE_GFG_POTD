
// problem -> https://www.geeksforgeeks.org/problems/check-for-bst/1

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    
    bool solve(Node* root,int min,int max)
    {
        if(root==NULL)  return true;
        
        if(root->data< min || root->data>=max)
        return false;
        
        
        return solve(root->left,min,root->data)&& solve(root->right,root->data,max);
        
        
       
    }
    
    bool isBST(Node* root) {
       return solve(root,INT_MIN,INT_MAX);
       
    }
};
