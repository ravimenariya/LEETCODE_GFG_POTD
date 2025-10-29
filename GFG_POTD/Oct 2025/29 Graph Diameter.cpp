class Solution {
    int solve(unordered_map<int,vector<int>>&graph,vector<bool>&visited,int curr,int&ans)
    {
        visited[curr]=true;
        int m1=-1,m2=-1;
        for(int i=0;i<graph[curr].size();i++)
        {
            if(visited[graph[curr][i]])     continue;
            int res=solve(graph,visited,graph[curr][i],ans);
            if(res>m1)  {
                m2=m1;
                m1=res;
            }
            else if(res>m2)     m2=res;
        }
        visited[curr]=false;
        m1++;m2++;
        ans=max(ans,m1+m2);
        return m1;
    }
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>graph;
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool>visited(V,false);
        int ans=0;
        solve(graph,visited,0,ans);
        return ans;
    }
};
