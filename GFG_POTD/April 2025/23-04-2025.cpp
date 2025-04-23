class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        sort(arr.begin(),arr.end());
        vector<int>ans;
        int n=arr.size();
        for(int i=0;i<n-1;i+=2)
            if(arr[i]!=arr[i+1])
            {
                ans.push_back(arr[i]);
                i--;
            }
        if(ans.size()<2)    ans.push_back(arr[n-1]);
        return ans;
    }
};
