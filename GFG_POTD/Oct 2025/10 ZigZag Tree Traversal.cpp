class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*>q;
        int p=0;
        q.push(root);
        vector<int>ans;
        
        while(!q.empty())
        {
            vector<int>v;
            int n=q.size();
            while(n--)
            {
                auto node=q.front();
                q.pop();
                v.push_back(node->data);
                
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            if(p%2) ans.insert(ans.end(),v.rbegin(),v.rend());
            else    ans.insert(ans.end(),v.begin(),v.end());
            p++;
        }
        return ans;
    }
};
