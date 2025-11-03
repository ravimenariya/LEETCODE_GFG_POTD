class Solution {
    bool solve(vector<vector<int>>&graph,vector<pair<bool,bool>>&processed,int curr)
    {
        processed[curr].first=true;
        int count=0;
        for(int i=0;i<graph[curr].size();i++)
        {
            if(!processed[graph[curr][i]].first && solve(graph,processed,graph[curr][i]))   count++;
            else if(processed[graph[curr][i]].second)   count++;
        }
        if(count!=graph[curr].size())   return false;
        
        processed[curr].second=true;
        return true;
    }
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>graph(V);
        for(auto e:edges)  graph[e[0]].push_back(e[1]);
        vector<pair<bool,bool>>processed(V,pair<bool,bool>(false,false));// visited,issafe
        for(int i=0;i<V;i++)
        {
            if(!processed[i].first)
                solve(graph,processed,i);
        }
        vector<int>safenodes;
        for(int i=0;i<V;i++)
        {
            if(processed[i].second)
                safenodes.push_back(i);
        }
        return safenodes;
    }
};
