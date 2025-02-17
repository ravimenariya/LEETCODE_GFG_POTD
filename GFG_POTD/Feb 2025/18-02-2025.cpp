
// Problem -> https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>>pq;
        for(auto&v:points)
        {
            int a=v[0]*v[0],b=v[1]*v[1];
            double dis=sqrt(a+b);
            pq.push({dis,v});
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
