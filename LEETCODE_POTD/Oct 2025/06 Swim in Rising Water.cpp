using MyTuple = tuple<int, int, int>;

struct Compare {
    bool operator()(const MyTuple& a, const MyTuple& b) {
        return a > b;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<MyTuple,vector<MyTuple>,Compare>pq;
        pq.push({grid[0][0],0,0});
        int n=grid.size();
        grid[0][0]=-1;

        vector<vector<int>>dir={{0,-1},{-1,0},{0,1},{1,0}};

        while(!pq.empty())
        {
            auto p=pq.top();
            int i=get<1>(p),j=get<2>(p);
            if(i==n-1 && j==n-1)    break;
            pq.pop();

            for(auto d:dir)
            {
                int i=get<1>(p)+d[0],j=get<2>(p)+d[1];
                if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==-1)  continue;
                int m=max(get<0>(p),grid[i][j]);
                pq.push({m,i,j});
                grid[i][j]=-1;
            }
        }
        return get<0>(pq.top());
    }
};
