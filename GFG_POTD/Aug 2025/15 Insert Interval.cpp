class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        int n=intervals.size(),inserted=0;
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++)
        {
            if(!inserted && intervals[i][0]>=newInterval[0])
            {
                if(i && ans.back()[1]>=newInterval[0])  
                        ans.back()[1]=max(ans.back()[1],newInterval[1]);
                else    ans.push_back(newInterval);
                while(i<n && ans.back()[1]>=intervals[i][0])
                {
                    ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                    i++;
                }
                i--;
                inserted=1;
            }
            else    ans.push_back(intervals[i]);
        }
        if(!inserted)   
            if(ans.back()[1]>=newInterval[0])  
                    ans.back()[1]=max(ans.back()[1],newInterval[1]);
            else    ans.push_back(newInterval);
        return ans;
    }
};
