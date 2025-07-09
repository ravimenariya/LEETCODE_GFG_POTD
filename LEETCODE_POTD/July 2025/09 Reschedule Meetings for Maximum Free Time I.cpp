class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>v;
        v.push_back(startTime[0]);
        for(int i=1;i<n;i++)
            v.push_back(startTime[i]-endTime[i-1]);
        v.push_back(eventTime-endTime[n-1]);

        int l=0,r=0,sum=0,ans=0;
        n=v.size();
        while(r<k)    sum+=v[r++];

        while(r<n)
        {
            sum+=v[r++];
            ans=max(ans,sum);
            sum-=v[l++];
        }
        return ans;
    }
};
