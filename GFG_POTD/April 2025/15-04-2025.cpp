class Solution {
    public:
      vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
          vector<int>dist(n,1e8);
          dist[src] = 0;
          
          for(int i = 0; i < n; i++){
              for(auto it : edges){
                  int u = it[0];
                  int v = it[1];
                  int w = it[2];
                  
                  if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                      dist[v] = dist[u] + w;
                  }
              }
          }
        
          for(auto it : edges){
              int u = it[0];
              int v = it[1];
              int w = it[2];
              
              if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                  return {-1};
              }
          }
          return dist;
      }
};
