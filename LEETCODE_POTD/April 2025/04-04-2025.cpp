/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<vector<TreeNode*>>paths;
    int maxd=-1;

    void solve(TreeNode* root,int d,vector<TreeNode*>& curr)
    {
        curr.push_back(root);
        if(!root->left && !root->right)
        {
            if(d>maxd)
            {
                paths.clear();
                maxd=d;
            }
            if(d>=maxd) paths.push_back(curr);
        }
        if(root->left)   solve(root->left,d+1,curr);
        if(root->right) solve(root->right,d+1,curr);
        curr.pop_back();
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*>curr;
        solve(root,0,curr);
        TreeNode* ans=paths[0][0];
        for(int j=0;j<paths[0].size();j++)
        {
            int f=0;
            int c=paths[0][j]->val;
            for(int i=0;i<paths.size();i++)
            {
                if(c!=paths[i][j]->val)
                {
                    f=1;
                    break;
                }
            }
            if(!f)    ans=paths[0][j];
            else break;
        }
        return ans;
    }
};
