// User function template for C++

class Solution {
  public:
  
  void solve(vector<vector<int>> &mat,int i,int j,int n,string &s,vector<vector<int>> visited,vector<string> &ans)
  {
      if(i==n-1 && j==n-1)
      {
          ans.push_back(s);
          return;
      }
      visited[i][j]=1;
      
      if(i+1<n && visited[i+1][j]!=1 && mat[i+1][j]!=0)
      {
        s+="D";
        solve(mat,i+1,j,n,s,visited,ans);
        
        s.pop_back();
      }
      
      if(j-1>=0 && visited[i][j-1]!=1 && mat[i][j-1]!=0)
      {
        s+="L";
        solve(mat,i,j-1,n,s,visited,ans);
        
        s.pop_back();
      }
      
      if(j+1<n && visited[i][j+1]!=1 && mat[i][j+1]!=0)
      {
        s+="R";
        solve(mat,i,j+1,n,s,visited,ans);
        
        s.pop_back();
      }
      
      if(i-1>=0 && visited[i-1][j]!=1 && mat[i-1][j]!=0)
      {
        s+="U";
        solve(mat,i-1,j,n,s,visited,ans);
        
        s.pop_back();
      }
      
      visited[i][j]=0;
      
      return;
  }
  
    vector<string> ratInMaze(vector<vector<int>> &mat) {
        int n=mat.size();
        string s="";
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<string> ans;
        
        if(mat[0][0]!=0 && mat[n-1][n-1]!=0)    
            solve(mat,0,0,n,s,visited,ans);
        
        return ans;
    }
};

