class Solution {
    void getArr(TreeNode* root,vector<int>&arr){
        if(!root)   return;
        getArr(root->left,arr);
        arr.push_back(root->val);
        getArr(root->right,arr);
    }

    TreeNode* createTree(vector<int>&arr,int st,int end){
        if(st>end)  return nullptr;

        int size=end-st+1;
        int curr=st+size/2;

        TreeNode* node=new TreeNode(arr[curr]);

        node->left=createTree(arr,st,curr-1);
        node->right=createTree(arr,curr+1,end);

        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        getArr(root,arr);

        return createTree(arr,0,arr.size()-1);
    }
};
