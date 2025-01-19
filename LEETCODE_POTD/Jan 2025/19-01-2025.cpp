#include <queue>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        if (n < 3 || m < 3) return 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][m - 1], i, m - 1});
            visited[i][0] = visited[i][m - 1] = true;
        }
        for (int j = 1; j < m - 1; j++) {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[n - 1][j], n - 1, j});
            visited[0][j] = visited[n - 1][j] = true;
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int waterTrapped = 0;

        while (!minHeap.empty()) {
            auto [height, x, y] = minHeap.top();
            minHeap.pop();
            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    minHeap.push({max(height, heightMap[nx][ny]), nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        return waterTrapped;
    }
};
