class Solution{
    void makef(int n,int m,vector<vector<char>>& grid,int i,int j)
    {
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]=='X')    return;
        
        if (grid[i][j]=='O'){
        grid[i][j]='f';
        makef(n,m,grid,i-1,j);
        makef(n,m,grid,i,j-1);
        makef(n,m,grid,i,j+1);
        makef(n,m,grid,i+1,j);
        }
    }
public:
    void fill(vector<vector<char>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
                if(grid[i][0]=='O')      makef(n,m,grid,i,0);
                if(grid[i][m-1]=='O')    makef(n,m,grid,i,m-1);
        }     
        
        for(int i=0;i<m;i++)
        {
                if(grid[0][i]=='O')      makef(n,m,grid,0,i);
                if(grid[n-1][i]=='O')    makef(n,m,grid,n-1,i);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='f')       grid[i][j]='O';
                else                     grid[i][j]='X';
            }
        }
    }
};
