
// Problem -> https://www.geeksforgeeks.org/problems/k-sum-paths/1

    void solve(Node* root,int&k,int sum,unordered_map<int,int>&ump,int&ans)
    {
        if(!root)   return;
        sum+=root->data;
        if(ump.find(sum-k)!=ump.end())
            ans+=ump[sum-k];
        ump[sum]++;
        solve(root->left,k,sum,ump,ans);
        solve(root->right,k,sum,ump,ans);
        ump[sum]--;
    }
  public:
    int sumK(Node *root, int k) {
        // code here
        int sum=0,ans=0;
        unordered_map<int,int>ump;
        ump[0]=1;
        solve(root,k,sum,ump,ans);
        return ans;
    }
};
