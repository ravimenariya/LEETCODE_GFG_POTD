class Solution {
    Node* solve(vector<int>&pre,vector<int>&post,unordered_map<int,int>&pmap,int&preIdx,int l,int r)
    {
        Node* node=new Node(pre[preIdx++]);
        if(l==r)  return node;
        
        int left_idx=pmap[pre[preIdx]];
        
        node->left=solve(pre,post,pmap,preIdx,l,left_idx);
        node->right=solve(pre,post,pmap,preIdx,left_idx+1,r-1);
        return node;
    }
  public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        unordered_map<int,int>pmap;
        for(int i=0;i<post.size();i++)  pmap[post[i]]=i;
        int preIdx=0;
        return solve(pre,post,pmap,preIdx,0,post.size()-1);
    }
};
