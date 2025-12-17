class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int start,end,n=intervals.size(),i=0;
        vector<vector<int>>ans;
         
        while(i<n){
           start=intervals[i][0];
           end=intervals[i][1];
           while(i+1<n && end>=intervals[i+1][0]){
               if(end<intervals[i+1][1])       end=intervals[i+1][1];
               i++;
           }
           ans.push_back({start,end});
           i++;
        }
        return ans;
    }
};
