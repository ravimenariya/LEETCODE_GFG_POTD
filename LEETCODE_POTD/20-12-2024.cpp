//

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        vector<TreeNode*>v;

        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                TreeNode* front=q.front();
                q.pop();
                if(level%2)
                v.push_back(front);
                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
            }
            if(level%2)
            {
                int l=0,r=v.size()-1;
                while(l<r)
                {
                    swap(v[l]->val,v[r]->val);
                    l++;
                    r--;
                }
            }
            v.clear();
            level++;
        }
        return root;
    }
};
