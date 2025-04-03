class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        int total=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]>0)
                {
                    total++;
                    if(grid[i][j]==2)
                        q.push({i,j});
                }
        
        if(!total)  return 0;
        
        int time=-1;

        while(!q.empty())
        {
            time++;
            int size=q.size();
            while(size--)
            {
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first,j=p.second;
                total--;
                if((i-1)>=0 && grid[i-1][j]==1)
                {
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                }
                if((j-1)>=0 && grid[i][j-1]==1)
                {
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                }
                if((i+1)<n && grid[i+1][j]==1)
                {
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                }
                if((j+1)<m && grid[i][j+1]==1)
                {
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                }
            }
        }
        if(total)   return -1;
        return time;
    }
};
