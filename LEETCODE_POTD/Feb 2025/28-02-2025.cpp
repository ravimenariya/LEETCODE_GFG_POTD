
// Problem -> https://leetcode.com/problems/shortest-common-supersequence/?envType=daily-question&envId=2025-02-28

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),n2=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(n2+1,0));

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n2;j++)
                if(str1[i-1]==str2[j-1])                   dp[i][j]=dp[i-1][j-1]+1;
                else    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        
        string s="";
        int i=n,j=n2;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i][j]==dp[i-1][j])
            {
                s+=str1[i-1];
                i--;
            }
            else
            {
                s+=str2[j-1];
                j--;
            }
        }
        while(i)
        {
            s+=str1[i-1];
            i--;
        }
        while(j)
        {
            s+=str2[j-1];
            j--;
        }
        reverse(s.begin(), s.end());
    
        return s;
    }
};
