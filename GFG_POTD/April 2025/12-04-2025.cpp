class Solution {
    void solve(vector<vector<int>>& image,int&n,int&m,int i,int j,int&prev,int&newc)
    {
        image[i][j]=newc;
        if((i-1)>=0 && image[i-1][j]==prev) solve(image,n,m,i-1,j,prev,newc);
        if((j-1)>=0 && image[i][j-1]==prev) solve(image,n,m,i,j-1,prev,newc);
        if((i+1)<n && image[i+1][j]==prev) solve(image,n,m,i+1,j,prev,newc);
        if((j+1)<m && image[i][j+1]==prev) solve(image,n,m,i,j+1,prev,newc);
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) {
        // Code here
        int prev=image[sr][sc],n=image.size(),m=image[0].size();
        if(prev!=newColor)    solve(image,n,m,sr,sc,prev,newColor);
        return image;
    }
};
