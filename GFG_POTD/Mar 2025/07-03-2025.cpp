
// problem -> https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        string s2=s;
        reverse(s.begin(),s.end());
        
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        
        return dp[n][n];
    }
};
