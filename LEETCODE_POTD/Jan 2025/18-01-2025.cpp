class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> costmatrix(n, vector<int>(m, INT_MAX));
        
        // Min-heap to process cells in order of least cost
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        // Directions for moving: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Push the starting point into the heap
        pq.push({0, 0, 0});  // {cost, row, col}
        costmatrix[0][0] = 0;
        
        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();
            
            // If we reach the bottom-right corner, return the cost
            if (x == n - 1 && y == m - 1) return cost;
            
            // Skip if we've already processed a better path for this cell
            if (cost > costmatrix[x][y]) continue;
            
            // Explore all four directions
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + directions[dir].first;
                int ny = y + directions[dir].second;
                int newCost = cost + (grid[x][y] == dir + 1 ? 0 : 1);
                
                // If the new cost is better, update and push to the heap
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && newCost < costmatrix[nx][ny]) {
                    costmatrix[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
        
        return -1;  // Should never be reached
    }
};
