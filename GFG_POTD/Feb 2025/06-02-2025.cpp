
// Problem -> https://www.geeksforgeeks.org/problems/construct-tree-1/1

class Solution {
  public:
  int searchvalue(vector<int>& inorder , int value , int s , int e){
      for(int i = s ; i<= e ; i++){
          if(inorder[i] == value){
              return i;
          }
      }
      return -1;
  }
  Node* buildtree(vector<int>& inorder , vector<int> & preorder , int &preindex , int s , int e){
      if(s > e){
          return NULL;
      }
      
      Node* root = new Node(preorder[preindex]);
      preindex++;
      
      int index = searchvalue(inorder , preorder[preindex -1] , s , e);
      
      root->left = buildtree(inorder , preorder , preindex , s , index -1);
      root->right = buildtree(inorder , preorder , preindex , index +1 , e);
      
      return root;
  }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
       int n = preorder.size();
       int preindex =0;
      Node* root = buildtree(inorder , preorder , preindex , 0 , n-1);
      
      return root;
    }
};
