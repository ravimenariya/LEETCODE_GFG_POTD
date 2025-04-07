class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int v,vector<vector<int>>& edges) {
        // Your code here
        vector<vector<int>>adj(v);
        for(auto&i:edges)
            adj[i[0]].push_back(i[1]);
            
        unordered_map<int,int>degree;
        for(int i=0;i<adj.size();i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            degree[adj[i][j]]++;
        }
        
        queue<int>q;
        for(int i=0;i<adj.size();i++)
        {
            if(degree[i]==0)
            q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty())
        {
            int front=q.front();
            ans.push_back(front);
            q.pop();
            for(int i=0;i<adj[front].size();i++)
                if(--degree[adj[front][i]]==0) 
                    q.push(adj[front][i]);
        }
        return ans;
    }
};
