class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n,vector<int>(n+1,0));
        for(auto q:queries)
        {
            for(int i=q[0];i<=q[2];i++)
            {
                mat[i][q[1]]+=1;
                mat[i][q[3]+1]-=1;
            }
        }   
        int curr=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                curr+=mat[i][j];
                mat[i][j]=curr;
            }
        }

        for(auto& row:mat)  row.pop_back();

        return mat;
    }
};
