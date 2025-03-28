
// Problem -> https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>>v;
        for(int i=0;i<start.size();i++) v.push_back({start[i],i});
        sort(v.begin(),v.end());
        int ans=1,end=finish[v[0].second];
        for(int i=1;i<v.size();i++)
        {
            if(end>=v[i].first && end>finish[v[i].second]) end=finish[v[i].second];
            else
            {
                end=finish[v[i].second];
                ans++;
            }
        }
        return ans;
    }
};
