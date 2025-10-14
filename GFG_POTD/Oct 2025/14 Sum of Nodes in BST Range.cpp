class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if(!root)   return 0;
        int sum=0;
        if(l<=root->data && root->data<=r)  sum+=root->data;
        if(root->data>l)     sum+=nodeSum(root->left,l,r);
        if(root->data<=r)    sum+=nodeSum(root->right,l,r);
        return sum;
    }
};
