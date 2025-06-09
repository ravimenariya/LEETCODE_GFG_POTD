class Solution {
    bool solve(Node* root,int prev,int next)
    {
        if(!root->left && !root->right)
        {
            if(prev==(root->data-1) && next==(root->data+1))    return true;
            return false;
        }
        if(root->left && solve(root->left,prev,root->data)) return true;
        if(root->right && solve(root->right,root->data,next))   return true;
        return false;
    }
  public:
    bool isDeadEnd(Node *root) {
        // Code here
        return solve(root,0,0);
    }
};
