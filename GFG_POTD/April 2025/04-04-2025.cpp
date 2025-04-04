class Solution {
    bool dfs(vector<vector<int>>& graph,unordered_map<int, bool>& visited,int src,int parent)
    {
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++)
            if(visited[graph[src][i]] && graph[src][i]!=parent) return true;
            else if (!visited[graph[src][i]] &&dfs(graph,visited,graph[src][i],src))  return true;
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>graph(V);
        for(auto&i:edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        unordered_map<int, bool> visited;
        for(int i=0;i<graph.size();i++)
        if(!visited[i] && dfs(graph,visited,i,-1))  return true;
        return false;
    }
    
};
