using pf=pair<double,vector<int>>;
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<pf,vector<pf>,greater<pf>>pq;
        for(auto v:points)
        {
            pq.push({sqrt(v[0]*v[0]+v[1]*v[1]),v});
        }
        vector<vector<int>>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
