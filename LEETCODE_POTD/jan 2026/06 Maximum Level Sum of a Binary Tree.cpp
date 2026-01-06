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
public:
    int maxLevelSum(TreeNode* root) {
        pair<long long,int>ans;
        ans.first=INT_MIN;
        queue<TreeNode* >q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
            int n=q.size();
            long long sum=0;
            while(n--)
            {
                TreeNode* front=q.front();
                q.pop();
                sum+=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(sum>ans.first)
            {
                ans.first=sum;
                ans.second=level;
            }
            level++;
        }
        return ans.second;
    }
};
