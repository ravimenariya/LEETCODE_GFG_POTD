class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int maxrow=0,maxcol=0,n=mat.size();
        vector<int>rows(n,0);
        vector<int>cols(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                rows[i]+=mat[i][j];
                cols[j]+=mat[i][j];
                maxrow=max(maxrow,rows[i]);
                maxcol=max(maxcol,cols[j]);
            }
        }
        
        if(maxcol>maxrow)
        {
            swap(maxcol,maxrow);
            rows.swap(cols);
        }
        
        int ans=n*maxrow-accumulate(rows.begin(),rows.end(),0);
        return ans;
    
    }
};
