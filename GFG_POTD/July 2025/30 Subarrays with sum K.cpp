class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>ump;
        ump[0]=1;
        int ans=0,currsum=0;
        for(int i:arr)
        {
            currsum+=i;
            ans+=ump[currsum-k];
            ump[currsum]++;
        }
        return ans;
    }
};
