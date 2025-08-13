class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int lucky=0,n=arr.size();
        multiset<int>st;
        for(int i:arr)
        {
            if(i%k==0)  lucky++;
            else        st.insert(k-i%k);
        }
        n=ceil(n/2.0)-lucky;
        if(n<=0)    return 0;
        auto it=next(st.begin(), n);
        int ans=accumulate(st.begin(),it,0);
        return ans;
    }
};
