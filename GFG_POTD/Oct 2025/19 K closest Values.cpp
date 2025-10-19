class Solution {
    void solve(Node* root,int&target, set<pair<int,int>>&st)
    {
        if(!root)   return;
        st.insert({abs(target-root->data),root->data});
        solve(root->left,target,st);
        solve(root->right,target,st);
    }
  public:
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        set<pair<int,int>>st;
        solve(root,target,st);
        vector<int>ans;
        auto it = st.begin();
        while(k-- && it!=st.end())
        {
            ans.push_back((*it).second);
            it++;
        }
        return ans;
    }
};
