class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        map<int,int>freq;
        int maxend=0,curr=0,ans=-1;
        for(auto i:intervals)
        {
            freq[i[0]]++;
            freq[i[1]+1]--;
            maxend=max(maxend,i[1]);
        }
        for(auto i:freq)
        {
            if(i.second<0 && curr>=k)  ans=max(ans,i.first-1);
            curr+=i.second;
            if(curr>=k)     ans=max(ans,i.first);
        }
        return ans;
    }
};
