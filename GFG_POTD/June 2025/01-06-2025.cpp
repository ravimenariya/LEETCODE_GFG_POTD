class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n=mat1.size(),p1=n-1,p2=n-1,count=0,f=0,sum;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum=mat1[i][j]+mat2[p1][p2];
                if(sum==x)    count++;
                else if(sum>x)
                {
                    if(p2==0)
                    {
                        if(p1==0)   {f=1;   break;}
                        p1--;
                        p2=n-1;
                    }
                    else    p2--;
                    j--;
                }
            }
            if(f)   break;
        }
        return count;
    }
};
