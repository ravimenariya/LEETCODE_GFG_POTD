
// Problem -> https://leetcode.com/problems/count-the-number-of-complete-components/?envType=daily-question&envId=2025-03-22

class Solution {
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, int &c_ver, int &c_edg) {
        visited[node] = true;
        c_ver++;

        for (int neighbor : graph[node]) {
            c_edg++;  
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, c_ver, c_edg);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int c_ver = 0, c_edg = 0;
                dfs(i, graph, visited, c_ver, c_edg);
                c_edg /= 2;

                if (c_edg == (c_ver * (c_ver - 1)) / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
