
// problem -> https://leetcode.com/problems/most-profitable-path-in-a-tree/?envType=daily-question&envId=2025-02-24

class Solution {
    vector<int> path;

    bool find_path(int bob, vector<vector<int>>& graph, int parent) {
        path.push_back(bob);
        if (bob == 0) return true;
        for (int i = 0; i < graph[bob].size(); i++)
            if (graph[bob][i] != parent && find_path(graph[bob][i], graph, bob)) return true;
        path.pop_back();
        return false;
    }

    void solve(vector<vector<int>>& graph, vector<int>& amount, unordered_map<int, bool>& visited,
               long long a_val, int a_node, int b_i, int& ans, int& m, int parent) {
        bool unmark_a = false, unmark_b = false;

        if (a_node == path[b_i] && !visited[a_node]) {
            a_val += amount[a_node] / 2;
            visited[a_node] = true;
            visited[path[b_i]] = true;
            unmark_a = true;
            unmark_b = true;
        }

        if (!visited[a_node]) {
            a_val += amount[a_node];
            visited[a_node] = true;
            unmark_a = true;
        }

        if (!visited[path[b_i]]) {
            visited[path[b_i]] = true;
            unmark_b = true;
        }

        bool is_called = false;
        for (int i = 0; i < graph[a_node].size(); i++) {
            if (graph[a_node][i] != parent) {
                is_called = true;
                solve(graph, amount, visited, a_val, graph[a_node][i],
                      (b_i < (m - 1)) ? b_i + 1 : b_i, ans, m, a_node);
            }
        }

        if (!is_called) ans = max(ans, (int)a_val);

        if (unmark_a) visited[a_node] = false;
        if (unmark_b) visited[path[b_i]] = false;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        for (auto& v : edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        find_path(bob, graph, -1);
        unordered_map<int, bool> visited;
        int ans = INT_MIN;
        int m = path.size();
        solve(graph, amount, visited, 0, 0, 0, ans, m, -1);
        return ans;
    }
};
