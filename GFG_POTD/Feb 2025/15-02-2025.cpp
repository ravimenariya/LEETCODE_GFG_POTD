
// Problem -> https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

class Solution {
    bool solve(Node* root ,Node* n,vector<Node*>&v)
    {
        if(root==nullptr)   return false;
        v.push_back(root);
        if(root->data==n->data) return true;
        if(solve(root->left,n,v))   return true;
        if(solve(root->right,n,v))  return true;
        v.pop_back();
        return false;
    }
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        if (!root || !n1 || !n2) return nullptr;
        vector<Node*> v1,v2;
        if(!solve(root,n1,v1) || !solve(root,n2,v2))    return nullptr;
        
        Node* ans=nullptr;
        int i=0,n=v1.size(),m=v2.size();
        while(i<n && i<m && v1[i]==v2[i])
        {
            ans=v1[i];
            i++;
        }
        return ans;
    }
};
