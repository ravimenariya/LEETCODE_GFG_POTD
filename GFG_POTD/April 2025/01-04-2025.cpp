class Solution {
    void FS(int node, vector<vector<int>> &graph, unordered_map<int, bool> &visited, vector<int> &ans)
{
    ans.push_back(node);
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
        if (!visited[graph[node][i]])
            FS(graph[node][i], graph, visited, ans);
}
  public:
    // Function to return a list containing the FS traversal of the graph.
    vector<int> dfs(vector<vector<int>>& graph) {
        // Code here
        unordered_map<int, bool> visited;
        vector<int> ans;
        FS(0, graph, visited, ans);
        return ans;
    }
};
