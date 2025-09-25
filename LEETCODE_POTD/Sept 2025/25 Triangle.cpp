class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                int p1=INT_MAX,p2=INT_MAX;
                if(j<i)    p1=triangle[i-1][j];
                if(j>0)    p2=triangle[i-1][j-1];
                triangle[i][j]+=min(p1,p2);
            }
        }
        return *min_element(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
    }
};
