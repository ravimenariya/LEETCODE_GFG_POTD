
// roblem -> https://www.geeksforgeeks.org/problems/level-order-traversal/1

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        Node* p=root;
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>ans;
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int>v;
            while(size--)
            {
                Node* front=q.front();
                v.push_back(front->data);
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
