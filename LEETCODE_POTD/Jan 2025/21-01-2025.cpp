class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m=grid[0].size();
        vector<vector<long long>>v(2,vector<long long>(m));
        v[0][0]=grid[0][0];
        for(int j=1;j<m;j++)    v[0][j]=v[0][j-1]+grid[0][j];
        v[1][m-1]=grid[1][m-1];
        for(int j=m-2;j>=0;j--) v[1][j]=v[1][j+1]+grid[1][j];
        
        long long sum1=v[0][m-1],sum2=v[1][0],ans=sum1-v[0][0],a,b;
        for(int j=1;j<m;j++)
        {
            a=sum1-v[0][j];
            b=sum2-v[1][j];
            if(b>a) a=b;
            if(a<ans)   ans=a;
        }
        return ans;
    }
};
