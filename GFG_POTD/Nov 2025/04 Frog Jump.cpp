 class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        if(n==1)    return 0;
        if(n==2)    return abs(height[0]-height[1]);
        
        vector<int>v(n,0);
        v[1]=abs(height[0]-height[1]);
        
        for(int i=2;i<n;i++)
            v[i]=min(v[i-1]+abs(height[i]-height[i-1]),v[i-2]+abs(height[i]-height[i-2]));
        
        return v[n-1];
    }
};
