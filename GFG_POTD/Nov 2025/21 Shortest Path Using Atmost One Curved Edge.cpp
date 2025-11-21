using tpl = tuple<int,int,int>;

class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {

        vector<vector<tpl>> graph(V);
        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2], e[3]});
            graph[e[1]].push_back({e[0], e[2], e[3]});
        }

        vector<vector<int>> dist(V, vector<int>(2, INT_MAX));
        dist[a][0] = 0;

        priority_queue<tpl,vector<tpl>,greater<tpl>> pq;

        pq.push({0, a, 0}); // dist, node, used_curved

        while (!pq.empty()) {
            auto [d, node, used] = pq.top(); pq.pop();
            if (d != dist[node][used]) continue;

            for (auto &tp : graph[node]) {
                int nxt = get<0>(tp);
                int w1  = get<1>(tp);
                int w2  = get<2>(tp);

                // straight edge
                if (d + w1 < dist[nxt][used]) {
                    dist[nxt][used] = d + w1;
                    pq.push({dist[nxt][used], nxt, used});
                }

                // curved edge - can only use if `used == 0`
                if (used == 0 && d + w2 < dist[nxt][1]) {
                    dist[nxt][1] = d + w2;
                    pq.push({dist[nxt][1], nxt, 1});
                }
            }
        }

        int ans = min(dist[b][0], dist[b][1]);
        return ans == INT_MAX ? -1 : ans;
    }
};
