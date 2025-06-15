class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n=arr.size(),l=1,r=*max_element(arr.begin(),arr.end()),m,ans;
        while(l<=r)
        {
            m=l+(r-l)/2;
            int s=0;
            for(int&i:arr)  s+=ceil((double)i/m);
            if(s<=k)    
            {
                ans=m;
                r=m-1;
            }
            else        l=m+1;
        }
        return ans;
    }
};
