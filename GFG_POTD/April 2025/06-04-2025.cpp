class Solution {
  public:
    bool dfs(vector<vector<int>> &graph,unordered_map<int, bool>& visited, unordered_map<int, bool>& currpath, int src)
{
    currpath[src] = true;
    visited[src]=true;
    for (int i = 0; i < graph[src].size(); i++)
        if (currpath[graph[src][i]] )
            return true;
        else if (dfs(graph,visited, currpath, graph[src][i]))
            return true;
    currpath[src]=false;
    return false;
}

bool isCyclic(int V,vector<vector<int>> &edges)
{
    vector<vector<int>>graph(V);
    for(auto&i:edges)
        graph[i[0]].push_back(i[1]);

    unordered_map<int, bool> currpath;
    unordered_map<int,bool> visited;
    for (int i = 0; i < graph.size(); i++)
        if (!currpath[i] && dfs(graph,visited, currpath, i))
            return true;
    return false;
}
};
