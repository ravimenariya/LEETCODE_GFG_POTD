class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        vector<int>v1(n,0),v2(n,0);
        for(int i=1;i<n;i++){
            v1[i]=max(v1[i-1],arr[i-1]);
            v2[n-i-1]=max(v2[n-i],arr[n-i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=(max(min(v1[i],v2[i]),arr[i])-arr[i]);
        
        return ans;
        
    }
};
