class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(),m=mat[0].size(),minele=mat[0][0],maxele=mat[0][m-1];
        for(int i=0;i<n;i++)
        {
            minele=min(minele,mat[i][0]);
            maxele=max(maxele,mat[i][m-1]);
        }
        int target=(m*n)/2;
        while(minele<=maxele)
        {
            int currele=minele+(maxele-minele)/2;
            int count=0;
            for(int i=0;i<n;i++)
            {
                int low=0,high=m-1,mid=-1;
                while(low<=high && mat[i][low]<=currele)
                {
                    mid=low+(high-low)/2;
                    if(mat[i][mid]<=currele)    low=mid+1;
                    else    high=mid-1;
                }
                count+=mid+1;
            }
            if(count<=target)   minele=currele+1;
            else                maxele=currele-1;
        }
        return minele;
    }
};
