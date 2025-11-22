class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V, false);
        int group = 0;  

        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (int v : graph[u])
                if (!visited[v]) dfs(v);
        };

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                group++;
                dfs(i);
            }
        }

        int E = edges.size();
        int extra = E - (V - group);

        if (extra < group - 1) return -1;
        return group - 1;
    }
};
