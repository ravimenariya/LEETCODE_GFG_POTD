class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        auto solve=[&](vector<int>prices){
            int i=0,j=prices.size()-1,val=0;
            while(i<=j)
            {
                val+=prices[i];
                i++;
                j-=k;
            }
            return val;
        };
        sort(prices.begin(),prices.end());
        int minPrice=solve(prices);
        reverse(prices.begin(),prices.end());
        int maxPrice=solve(prices);
        
        return {minPrice,maxPrice};
    }
};
