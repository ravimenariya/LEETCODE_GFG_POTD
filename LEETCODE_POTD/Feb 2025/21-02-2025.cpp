
/*

Problem ->  https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/?envType=daily-question&envId=2025-02-21

1261. Find Elements in a Contaminated Binary Tree

Given a binary tree with the following rules:

root.val == 0
For any treeNode:
If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.

 */
class FindElements {
    set<int>st={0};
    void solve(TreeNode* root, int prev)
    {
        if(root->left)
        {
            st.insert(2*prev+1);
            solve(root->left,2*prev+1);
        }
        if(root->right)
        {
            st.insert(2*prev+2);
            solve(root->right,2*prev+2);
        }
    }
public:
    FindElements(TreeNode* root) {
        solve(root,0);
    }
    
    bool find(int target) {
        return st.find(target)!=st.end();
    }
};
