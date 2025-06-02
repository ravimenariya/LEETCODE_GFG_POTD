class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        if(grid[0][0]==1)   return 0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>mat(n+1,vector<int>(m+1,0));
        mat[1][1]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==0)   mat[i+1][j+1]+=mat[i+1][j] + mat[i][j+1];
        return mat[n][m];
    }
};
