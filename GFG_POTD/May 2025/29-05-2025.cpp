class Solution {
    int ans=0,asum=0;
    void solve(Node* root,int n,int sum)
    {
        if(!root)
        {
            if(n>ans)
            {
                ans=n;
                asum=sum;
            }
            else if(n==ans) asum=max(asum,sum);
            return;
        }
        solve(root->left,n+1,sum+root->data);
        solve(root->right,n+1,sum+root->data);
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        solve(root,0,0);
        return asum;
    }
};
