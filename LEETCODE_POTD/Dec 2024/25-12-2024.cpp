class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        if(root)
        q.push(root);
        vector<int>ans;
        while(!q.empty())
        {
            int m=INT_MIN;
            int n=q.size();
            while(n--)
            {
                TreeNode* front=q.front();
                q.pop();
                m=max(m,front->val);
                if(front->left) q.push(front->left);
                if(front->right)q.push(front->right);
            }
            ans.push_back(m);
        }
        return ans;
    }
};
