class Solution {
    vector<int> dijkstra(const vector<vector<pair<int,int>>> &graph, int src) {
        vector<int> dist(26, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

public:
    int minCost(string &s, string &t, vector<vector<char>> &transform, vector<int> &cost) {
        vector<vector<pair<int,int>>> graph(26);

        // directed edges
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            int w = cost[i];
            graph[u].push_back({v, w});
        }

        // run dijkstra from each node
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; i++) {
            dist[i] = dijkstra(graph, i);
        }

        long long ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            if (a == b) continue;

            int best = INT_MAX;

            // meeting point strategy
            for (int k = 0; k < 26; k++) {
                if (dist[a][k] != INT_MAX && dist[b][k] != INT_MAX) {
                    best = min(best, dist[a][k] + dist[b][k]);
                }
            }

            if (best == INT_MAX) return -1;
            ans += best;
        }

        return ans;
    }
};
