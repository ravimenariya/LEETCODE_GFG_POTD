class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r1=-1,r2=-1,c1=INT_MAX,c2=-1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j])
                {
                   if(r1==-1)   r1=i;
                   r2=max(i,r2);
                   c1=min(j,c1);
                   c2=max(j,c2);
                }
            }
        }
        return (r2-r1+1)*(c2-c1+1);
    }
};
