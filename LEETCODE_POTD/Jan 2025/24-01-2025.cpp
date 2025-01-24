// problem -> https://leetcode.com/problems/find-eventual-safe-states/?envType=daily-question&envId=2025-01-24

class Solution {
    bool dfs(vector<vector<int>>& graph, int curr, vector<int>& state) {
        if (state[curr] != 0) {
            return state[curr] == 2; // If already visited, check if it's safe
        }

        state[curr] = 1; // Mark node as visiting
        for (int neighbor : graph[curr]) {
            if (state[neighbor] == 1 || !dfs(graph, neighbor, state)) {
                state[curr] = 3; // Mark node as not safe
                return false;
            }
        }
        state[curr] = 2; // Mark node as safe
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0: unvisited, 1: visiting, 2: safe, 3: not safe
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, state)) {
                result.push_back(i);
            }
        }
        return result;
    }
};
