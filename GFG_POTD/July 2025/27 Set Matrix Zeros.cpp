class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int col0=1;
        for(int i=0;i<mat.size();i++)
        {
            if (mat[i][0] == 0) col0 = 0;
            for(int j=1;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                {
                    if(j==0)    col0=0;
                    mat[0][j]=0;
                    mat[i][0]=0;
                }
            }
        }
        for(int i=1;i<mat.size();i++)
        {
            for(int j=1;j<mat[i].size();j++)
            {
                if(mat[0][j]==0 || mat[i][0]==0)
                {
                    mat[i][j]=0;
                }
            }
        }
        if(mat[0][0]==0){
            for(int j=0;j<mat[0].size();j++)    mat[0][j]=0;
        }
        if(col0==0){
            for(int i=0;i<mat.size();i++)       mat[i][0]=0;
        }
    }
};
