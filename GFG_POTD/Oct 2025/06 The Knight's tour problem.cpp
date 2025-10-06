class Solution {
    vector<vector<int>>dir={{-1,-2},{1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1}};
    bool solve(vector<vector<int>>&order,vector<vector<bool>>&visited,int i,int j,int n,int pos)
    {
        if(i<0 || j<0 || i>=n || j>=n)    return false;
        visited[i][j]=true;
        order[i][j]=pos;
        
        if(pos==(n*n-1))    return true;
        
        for(auto d:dir)
        {
            int newi=i+d[0],newj=j+d[1];
            if(newi>=n || newi<0 || newj>=n || newj<0 || visited[newi][newj])   continue;
            
            if(solve(order,visited,newi,newj,n,pos+1))
                return true;
        }
        visited[i][j]=false;
        return false;
    }
  public:
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>>order(n,vector<int>(n,-1));
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0]=true;
        order[0][0]=0;
        
        if(solve(order,visited,0,0,n,0))    return order;
        
        order={{-1}};
        
        return order;
    }
};
