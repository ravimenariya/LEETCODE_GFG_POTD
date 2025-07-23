class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int ans=0,n=arr.size(),j=n-1;
        for(int i=0;i<n;i++)
        {
            ans+=(i+j+i*j+1)*arr[i];
            j--;
        }
        return ans;
    }
};
