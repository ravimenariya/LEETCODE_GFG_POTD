
// problem -> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/1553059043/?envType=daily-question&envId=2025-02-23

class Solution {
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,int pre_st,int pre_end,int post_st,int post_end,unordered_map<int,int>&post_idx)
    {
        if(pre_st>pre_end)  return NULL;
        TreeNode* root=new TreeNode(preorder[pre_st]);
        if(pre_st+1>pre_end) return root;
        int nend=post_idx[preorder[pre_st+1]];
        int size=nend-post_st;
        root->left=solve(preorder,postorder,pre_st+1,pre_st+1+size,post_st,nend,post_idx);
        root->right=solve(preorder,postorder,pre_st+1+size+1,pre_end,nend+1,post_end-1,post_idx);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        unordered_map<int,int>post_idx;
        for(int i=0;i<n;i++)    post_idx[postorder[i]]=i;
        return solve(preorder,postorder,0,n-1,0,n-1,post_idx);
    }
};
