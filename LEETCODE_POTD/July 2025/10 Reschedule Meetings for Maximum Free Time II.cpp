class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1;i<n;i++)
            freeTime.push_back(startTime[i]-endTime[i-1]);
        freeTime.push_back(eventTime-endTime[n-1]);

        vector<int>left(n,0);
        left[0]=0;
        for(int i=1;i<n;i++)
            left[i]=max(left[i-1],freeTime[i-1]);
        
        vector<int>right(n,0);
        right[n-1]=0;
        for(int i=n-2;i>=0;i--)
            right[i]=max(right[i+1],freeTime[i+2]);
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int dur=endTime[i]-startTime[i];
            int time=freeTime[i]+freeTime[i+1];
            if(max(left[i],right[i])>=dur)  time+=dur;
            // cout<<"i="<<i<<", l="<<left[i]<<", r="<<right[i]<<", t="<<time<<endl;
            ans=max(ans,time);
        }
        return ans;
    }
};
