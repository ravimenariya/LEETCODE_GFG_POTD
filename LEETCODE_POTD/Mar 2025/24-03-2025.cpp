
// Problem -> https://leetcode.com/problems/count-days-without-meetings/?envType=daily-question&envId=2025-03-24

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=meetings[0][0]-1,n=meetings.size(),m_end=0;
        for(int i=0;i<n-1;i++)
        {
            m_end=max(m_end,meetings[i][1]);
            if(meetings[i+1][0]>m_end)   ans+=meetings[i+1][0]-m_end-1;
        }
        m_end=max(m_end,meetings[n-1][1]);
        if((days-m_end)>0)  ans+=days-m_end;
        return ans;
    }
};
