// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int f;
        int n=mat.size();
        
        for(int i=0;i<n;i++)
        {
            f=1;
            for(int j=0;j<n;j++)
            {
                if(i!=j && mat[i][j]==1)
                {
                    f=0;
                    break;
                }
            }
            if(f==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j && mat[j][i]==0)
                    {
                        f=0;
                        break;
                    }
                }
                if(f==1)
                return i;
            }
        }
        
        return -1;
    }
};
