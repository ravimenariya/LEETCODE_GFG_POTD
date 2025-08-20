class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>change(n,vector<int>(m+1,0));
        for(auto op:opr)
        {
            for(int i=op[1];i<=op[3];i++)
            {
                change[i][op[2]]+=op[0];
                change[i][op[4]+1]-=op[0];
            }
        }
        int curr=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                curr+=change[i][j];
                mat[i][j]+=curr;
                if(j==(m-1))    curr+=change[i][j+1];
            }
        }
        return mat;
    }
};
