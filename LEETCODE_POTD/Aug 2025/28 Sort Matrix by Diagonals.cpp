class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),k=0;
        // desc sort
        while(k<n)
        {
            int i=k,j=0,p=0;
            vector<int>v;
            while(i<n )            v.push_back(grid[i++][j++]);
            sort(v.rbegin(),v.rend());
            i=k,j=0;
            while(i<n)             grid[i++][j++]=v[p++];
            k++;
        }
        
        // Asc sort
        k=1;
        while(k<m)
        {
            int i=0,j=k,p=0;
            vector<int>v;
            while(j<m )            v.push_back(grid[i++][j++]);
            sort(v.begin(),v.end());
            i=0,j=k;
            while(j<m)             grid[i++][j++]=v[p++];
            k++;
        }

        return grid;
    }
};
