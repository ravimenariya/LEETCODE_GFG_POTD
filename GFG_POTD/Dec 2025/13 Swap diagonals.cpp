class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(),p1=0,p2=n-1;
        for(int i=0;i<n;i++){
            swap(mat[i][p1],mat[i][p2]);
            p1++;p2--;
        }
    }
};
