
// problem -> https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

class Solution {
    void solve(Node* root,int&k,int&curr,int&ans)
    {
        if(!root)   return;
        solve(root->left,k,curr,ans);
        if(ans!=-1) return;
        curr++;
        if(curr==k)
        {
            ans=root->data;
            return;
        }
        solve(root->right,k,curr,ans);
        if(ans!=-1) return;
        
    }
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        int ans=-1,curr=0;
        solve(root,k,curr,ans);
        return ans;
    }
};
