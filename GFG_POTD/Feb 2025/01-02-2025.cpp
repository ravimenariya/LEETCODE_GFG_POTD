
// problem -> https://www.geeksforgeeks.org/problems/word-search/1

class Solution {
    bool solve(vector<vector<char>>& mat, string& word,int i,int j,int &n,int&m,vector<vector<bool>>&visited,int&len,int k)
    {
        if(k==(len-1))  return true;
        visited[i][j]=true;
        if((i-1)>=0 && mat[i-1][j]==word[k+1] && !visited[i-1][j] && solve(mat,word,i-1,j,n,m,visited,len,k+1)) return true;
        if((j-1)>=0 && mat[i][j-1]==word[k+1] && !visited[i][j-1] && solve(mat,word,i,j-1,n,m,visited,len,k+1)) return true;
        if((i+1)<n && mat[i+1][j]==word[k+1] && !visited[i+1][j] && solve(mat,word,i+1,j,n,m,visited,len,k+1)) return true;
        if((j+1)<m && mat[i][j+1]==word[k+1] && !visited[i][j+1] && solve(mat,word,i,j+1,n,m,visited,len,k+1)) return true;
        visited[i][j]=false;
        return false;
    }
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n=mat.size(),m=mat[0].size(),len=word.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                vector<vector<bool>>visited(n,vector<bool>(m,false));
                if(mat[i][j] == word[0] && solve(mat,word,i,j,n,m,visited,len,0))
                return true;
            }
        
        return false;
    }
};
