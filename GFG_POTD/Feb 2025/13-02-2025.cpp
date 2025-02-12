
//  problem -> https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

class Solution {
    bool solve(Node* root,int target,unordered_map<int,bool>&ump)
    {
        if(!root)   return false;
        if(ump[target-root->data])  return true;
        ump[root->data]=true;
        if(solve(root->left,target,ump))    return true;
        if(solve(root->right,target,ump))    return true;
        return false;
    }
  public:
    bool findTarget(Node *root, int target) {
        // your code here.
        unordered_map<int,bool>ump;
        return solve(root,target,ump);
    }
};
