class Solution {
    void dfs(unordered_map<int,vector<int>>&graph,unordered_map<int,set<int>>&ump,vector<bool>&visited,vector<pair<int,bool>>&gp_state,int curr,int&gp)
    {
        visited[curr]=true;
        ump[gp].insert(curr);
        gp_state[curr].first=gp;

        for(int i=0;i<graph[curr].size();i++)
        {
            if(!visited[graph[curr][i]])
                dfs(graph,ump,visited,gp_state,graph[curr][i],gp);
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<pair<int,bool>>gp_state(c+1,pair<int,bool>({0,true}));// group, station state
        unordered_map<int,set<int>>ump;// group, active stations
        
        unordered_map<int,vector<int>>graph; // just to keep track of connections
        
        for(auto c:connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        vector<bool>visited(c+1,false);
        int gp=0;
        for(int i=1;i<=c;i++)
        {
            if(!visited[i])  // mow we are creating groups of all connected stations
            {
                gp++;
                dfs(graph,ump,visited,gp_state,i,gp);
            }
        }

        vector<int>ans;
        for(auto q:queries)
        {
            if(q[0]==1)
            {
                if(gp_state[q[1]].second)    ans.push_back(q[1]); // q[1] is active so return q[1]
                else {
                    if(ump[gp_state[q[1]].first].empty())   ans.push_back(-1); // if no station is active in this group
                    else    ans.push_back(*ump[gp_state[q[1]].first].begin()); // return min active station
                }
            }
            else{
                gp_state[q[1]].second=false;
                ump[gp_state[q[1]].first].erase(q[1]);
            }
        }
        return ans;
    }
};
