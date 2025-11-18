class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF), ways(n, 0);
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  // {distance, node}

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;

            for (auto [v, w] : g[u]) {
                long long nd = d + w;

                if (nd < dist[v]) {          // shorter path found
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                }
                else if (nd == dist[v]) {    // same shortest path
                    ways[v] += ways[u];
                }
            }
        }

        return ways[n - 1];
    }
};
