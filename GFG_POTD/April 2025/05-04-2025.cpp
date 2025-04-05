class Solution {
  public:
    // Function to find the number of islands.
    int countIslands(vector<vector<char>>& grid) {
        int count=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='L')
                {
                    count++;
                    solve(grid,i,j);
                }
            }
        }
        return count;
    }
    
    void solve(vector<vector<char>>& grid,int i,int j)
    {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]!='L')    return;
        
        grid[i][j]='W';
        
        solve(grid,i+1,j);
        solve(grid,i,j+1);
        solve(grid,i-1,j);
        solve(grid,i,j-1);
        solve(grid,i+1,j+1);
        solve(grid,i+1,j-1);
        solve(grid,i-1,j+1);
        solve(grid,i-1,j-1);
    }
};
