class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n=heights.size(),
        l=*min_element(heights.begin(),heights.end()),
        h=*max_element(heights.begin(),heights.end()),
        ans=INT_MAX;
        
        auto find_cost=[&](int ch){
            int curr_cost=0;
            for(int i=0;i<n;i++){
                curr_cost+=(abs(ch-heights[i])*cost[i]);
            }
            return curr_cost;
        };
        
        while(l<=h){
            int m=l+(h-l)/2;
            
            int c_m=find_cost(m);
            int c_ml=find_cost(m-1);
            int c_mh=find_cost(m+1);
            
            if(c_m<=c_ml && c_m<=c_mh)  {
                ans=min(ans,c_m);
                break;
            }
            else if(c_m<=c_ml && c_m>c_mh)  l=m+1;
            else    h=m-1;
        }

        return ans;
    }
};
