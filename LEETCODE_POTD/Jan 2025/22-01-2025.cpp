class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(),m=isWater[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                {
                    isWater[i][j]=0;
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        vector<pair<int,int>> dir={{0,-1},{0,1},{-1,0},{1,0}};
        int level=1;
        while(!q.empty())
        {
            int size=q.size();

            while(size--)
            {
            auto curr=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int i=curr.first+dir[k].first;
                int j=curr.second+dir[k].second;
                if(i>=0 && j>=0 && i<n && j<m && visited[i][j]!=1)
                {
                    isWater[i][j]=level;
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
            }
            level++;
        }
        return isWater;
    }
};
