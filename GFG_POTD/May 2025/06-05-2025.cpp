class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        if(!root)   return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            ans.push_back(q.front()->data);
            int n=q.size();
            while(n--)
            {
                Node* front=q.front();
                q.pop();
                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
            }
        }
        return ans;
    }
};
