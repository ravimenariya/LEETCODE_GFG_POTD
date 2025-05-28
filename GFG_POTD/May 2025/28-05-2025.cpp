class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        unordered_map<int,vector<int>>rows;
        unordered_map<int,vector<int>>cols;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]==1)
                {
                    rows[i].push_back(j);
                    cols[j].push_back(i);
                }
        for(auto&v:rows)
        {
            if(v.second.size()<2)  continue;
            for(int j=0;j<v.second.size();j++)
            {
                for(int k=j+1;k<v.second.size();k++)
                {
                    for(int l=0;l<cols[v.second[j]].size();l++)
                    {
                        if(cols[v.second[j]][l]<=v.first)  continue;
                        if(mat[cols[v.second[j]][l]][v.second[k]]==1)    return true;
                    }
                }
            }
        }
        return false;
    }
};
