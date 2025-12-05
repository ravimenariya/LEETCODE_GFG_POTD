class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int m1=INT_MAX,m2=INT_MAX;
        for(int i:costs[0]){
            if(i<m1){
                m2=m1;
                m1=i;
            }
            else if(i<m2)   m2=i;
        }
        
        if(costs.size()==1) return m1;
        
        if(costs[0].size()<2)   return -1;
        
        for(int i=1;i<costs.size();i++)
        {
            int nm1=INT_MAX,nm2=INT_MAX;
            for(int j=0;j<costs[i].size();j++)
            {
                if(costs[i-1][j]==m1)   costs[i][j]+=m2;
                else                    costs[i][j]+=m1;
                
                if(costs[i][j]<nm1){
                    nm2=nm1;
                    nm1=costs[i][j];
                }
                else if(costs[i][j]<nm2)   nm2=costs[i][j];
            }
            m1=nm1;m2=nm2;
        }

        return m1;
    }
};
