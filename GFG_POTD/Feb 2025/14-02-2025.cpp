
// Problem -> https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

class Solution {
    vector<Node*>v;
    void solve(Node* root,vector<Node*>&v)
    {
        if(!root) return;
        solve(root->left,v);
        v.push_back(root);
        solve(root->right,v);
    }
  public:
    void correctBST(Node* root) {
        // add code here.
        vector<Node*>v;
        solve(root,v);
        vector<Node*>temp(v.begin(),v.end());
        sort(temp.begin(),temp.end(),[](Node* a,Node* b){return a->data<b->data;});
        int i=0;
        while(v[i]==temp[i])i++;
        int t=v[i]->data;
        v[i]->data=temp[i]->data;
        temp[i]->data=t;
    }
};
