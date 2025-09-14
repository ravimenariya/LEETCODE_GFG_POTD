class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n=gas.size();
        vector<int>v(n,0);
        v[0]=gas[0]-cost[0];
        for(int i=1;i<n;i++)           v[i]=gas[i]-cost[i];
        
        long long sum=accumulate(v.begin(),v.end(),0);
        if(sum<0)   return -1;
        sum=0;
        int l=0,r=0;

        while(r<n)
        {
            sum+=v[r];
            r++;
            while(sum<0 && l<r)
            {
                sum-=v[l];
                l++;
            }
        }

        return l;
    }
};
