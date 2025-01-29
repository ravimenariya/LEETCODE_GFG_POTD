
// problem -> https://leetcode.com/problems/redundant-connection/?envType=daily-question&envId=2025-01-29

class Solution {
    bool dfs(vector<vector<int>> &graph, unordered_map<int, bool> &visited,vector<int>& path, int src, int parent,int& loop)
{
    visited[src] = true;
    path.push_back(src);
    for (int i = 0; i < graph[src].size(); i++)
        if (visited[graph[src][i]] && graph[src][i] != parent)
        {
            loop=graph[src][i];
            return true;
        }
        else if (!visited[graph[src][i]] && dfs(graph, visited,path, graph[src][i], src,loop))
            return true;
    path.pop_back();
    return false;
}

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (auto &edge : edges) {
            n = max(n, max(edge[0], edge[1])); 
        }

        vector<vector<int>>graph(n+1);
        for(auto&i:edges)   {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        unordered_map<int,bool>visited;
        vector<int>path;
        int loop;
        dfs(graph,visited,path,1,-1,loop);

        int i=0;
        while(path[i]!=loop)    i++;

        path.erase(path.begin(),path.begin()+i);

        reverse(edges.begin(),edges.end());
        for(auto&v:edges)
        {
            if(find(path.begin(), path.end(), v[0])!=path.end() && find(path.begin(), path.end(), v[1])!=path.end())
            return v;
        }
        return path;
    }
};
