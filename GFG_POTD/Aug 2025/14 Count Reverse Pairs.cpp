class Solution {
  public:
    int countRevPairs(vector<int> &arr) {
        // Code here
        vector<int>st;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            auto it=upper_bound(st.begin(),st.end(),arr[i]); 
            if(it!=st.end())     ans+=(st.end()-it);
            auto it2 = lower_bound(st.begin(), st.end(), ceil(arr[i]/2.0));
            st.insert(it2, ceil(arr[i]/2.0));
        }
        return ans;
    }
};
