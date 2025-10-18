class Solution {
    int countnodes(Node* root)
    {
        if(!root)   return 0;
        return 1 + countnodes(root->left) + countnodes(root->right);
    }
    
    int getnode(Node* root, int&m)
    {
        if(!root)   return 0;
        int left=getnode(root->left,m);
        if(left)    return left;
        m--;
        if(m==0)  return  root->data;
        int right=getnode(root->right,m);
        if(right)    return right;
        return 0;
    }
  public:
    int findMedian(Node* root) {
        // Code here
        int count=countnodes( root);
        int m=ceil(count/2.0);
        return getnode( root,m);
    }
};
