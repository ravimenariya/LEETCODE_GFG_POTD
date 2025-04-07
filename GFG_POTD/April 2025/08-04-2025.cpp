class Solution {
    bool bfs(vector<vector<int>>& graph, int src, int dest) {
        vector<bool> visited(graph.size(), false);
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (neighbor == dest) return true;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }

public:
    bool isBridge(int V, vector<vector<int>>& edges, int c, int d) {
        vector<vector<int>> graph(V);
        for (auto& edge : edges) {
            if ((edge[0] == c && edge[1] == d) || (edge[0] == d && edge[1] == c))    continue;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return !bfs(graph, c, d);
    }
};
