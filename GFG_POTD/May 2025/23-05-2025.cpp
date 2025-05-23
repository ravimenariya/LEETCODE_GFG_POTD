class Solution {
    int solve(int m,int n,int sum,int x,vector<vector<int>>&dp)
    {
        int ways=0;
        if(n==0)        return sum==x?1:0;
        if(dp[n][sum]!=-1)  return dp[n][sum];
        for(int i=1;i<=m;i++)
        {
            if((sum+i)>x)   break;
            ways+=solve(m,n-1,sum+i,x,dp);
        }
        return dp[n][sum]=ways;
    }
    
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return solve(m,n,0,x,dp);
    }
};
