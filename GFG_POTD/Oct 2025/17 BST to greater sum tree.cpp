/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
    int solve(Node* root,int&currsum)
    {
        if(!root)   return 0;
        int right=solve(root->right,currsum);
        currsum+=root->data;
        root->data=currsum-root->data;
        int left=solve(root->left,currsum);
        return currsum;
    }
  public:
    void transformTree(Node *root) {
        // code here
        int currsum=0;
        solve(root,currsum);
    }
};
