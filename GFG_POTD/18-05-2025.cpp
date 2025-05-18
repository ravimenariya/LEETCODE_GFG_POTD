class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        queue<Node*>q;
        q.push(root);
        int f=1;
        vector<int>ans;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>arr;
            while(n--)
            {
                Node* front=q.front();
                q.pop();
                arr.push_back(front->data);
                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
            }
            if(f%2!=0)  reverse(arr.begin(),arr.end());
            ans.insert(ans.end(),arr.begin(),arr.end());
            f++;
        }
        return ans;
    }
};
