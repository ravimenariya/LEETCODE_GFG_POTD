class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here    
        if(root->data<l )    
        {
            if( root->right)    return removekeys(root->right,l,r);
            else                return nullptr;
        }
        else if (root->data>r )  
        {
            if( root->left)    return removekeys(root->left,l,r);
            else                return nullptr;
        }
        else {
            if(root->left)  root->left=removekeys(root->left,l,r);
            if(root->right) root->right=removekeys(root->right,l,r);
        }
        return root;
    }
};
