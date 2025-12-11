class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int,int>> row(n+1, {INT_MAX, INT_MIN}), cols(n+1, {INT_MAX, INT_MIN});
        for (auto &b : buildings) {
            row[b[0]].first  = min(row[b[0]].first, b[1]);
            row[b[0]].second = max(row[b[0]].second, b[1]);

            cols[b[1]].first  = min(cols[b[1]].first, b[0]);
            cols[b[1]].second = max(cols[b[1]].second, b[0]);
        }
        int ans=0;
        for(auto b:buildings) {
            if(row[b[0]].first < b[1] && b[1] < row[b[0]].second
              && cols[b[1]].first < b[0] && b[0] < cols[b[1]].second)
              ans++;
        }

        return ans;
    }
};
