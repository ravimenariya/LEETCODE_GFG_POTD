class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int ans=0,currsum=0,m=prices[0];
        
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<m)    m=prices[i];
            currsum=prices[i]-m;
            ans=max(ans,currsum);
        }
        return ans;
    }
};

