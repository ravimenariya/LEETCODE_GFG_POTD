
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &graph) {
        unordered_map<int, bool> visited;
    queue<int> q;
    vector<int> ans;
        q.push(0);
        while (!q.empty())
        {
            int currnode = q.front();
            q.pop();
            if (visited[currnode])
                continue;
            visited[currnode] = true;
            ans.push_back(currnode);
            for (int i = 0; i < graph[currnode].size(); i++)
            {
                q.push(graph[currnode][i]);
            }
        }
    
    return ans;
    }
};
