class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int d=-1,n=mat.size(),m=mat[0].size(),i=0,j=0;
        vector<int>ans;
        while(i<n && j<m)
        {
            while(i>=0 && i<n && j>=0 && j<m)
            {
                ans.push_back(mat[i][j]);
                i+=d;
                j-=d;
            }
            if(d==-1)
            {
                d=1;
                if(j<m) i=0;
                else {
                    j=m-1;
                    i+=2;
                }
            }
            else {
                d=-1;
                if(i<n) j=0;
                else {
                    i=n-1;
                    j+=2;
                }
            }
        }
        return ans;
    }
};
