class Solution {
    int pos=1;
  public:
    int kthSmallest(Node *root, int k) {
        // code here
        if(!root->left && !root->right) 
        {
            if(pos==k)  return root->data;
            pos++;
            return -1;
        }
        
        if(root->left)
        {
            int left=kthSmallest(root->left,k);
            if(left!=-1)    return left;
        }
        
        if(pos==k)  return root->data;
        pos++;
        
        if(root->right)
        {
            int right=kthSmallest(root->right,k);
            if(right!=-1)   return right;
        }
        
        return -1;
    }
};
