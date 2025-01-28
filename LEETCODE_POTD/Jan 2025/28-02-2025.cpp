
// problem -> https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/?envType=daily-question&envId=2025-01-28

class Solution {
    void solve(vector<vector<int>>& grid,int i,int j,int& sum,int&n,int&m)
    {
        sum+=grid[i][j];
        grid[i][j]=-1;
        //right
        if((j+1)<m  && grid[i][j+1]!=0 && grid[i][j+1]!=-1) solve(grid,i,j+1,sum,n,m);
        //down
        if((i+1)<n  && grid[i+1][j]!=0 && grid[i+1][j]!=-1) solve(grid,i+1,j,sum,n,m);
        //up
        if((i-1)>=0  && grid[i-1][j]!=0 && grid[i-1][j]!=-1) solve(grid,i-1,j,sum,n,m);
        //left
        if((j-1)>=0  && grid[i][j-1]!=0 && grid[i][j-1]!=-1) solve(grid,i,j-1,sum,n,m);
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && grid[i][j]!=-1)
                {
                    int sum=0;
                    solve(grid,i,j,sum,n,m);
                    if(sum>ans) ans=sum;
                }
            }
        }
        return ans;
    }
};
