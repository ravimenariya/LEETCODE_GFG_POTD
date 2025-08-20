class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(),m=mat[0].size(),ans_max=INT_MIN;
        
        auto kadanes=[&](vector<int>v){
          int maxSum=INT_MIN,currSum=0;
          for(int i:v){
              currSum=max(i,i+currSum);
              maxSum=max(maxSum,currSum);
          }
          ans_max=max(ans_max,maxSum);
        };
        
        for(int i=0;i<n;i++)
        {
            vector<int>sum(m,0);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)    sum[k]+=mat[j][k];
                kadanes(sum);
            }
        }
        
        return ans_max;
    }
};
