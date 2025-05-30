class Solution {
    stack<int> solve(vector<int>& edges,int n)
    {
        unordered_map<int,bool>visited;
        stack<int>s;
        while(!visited[n] && n!=-1)
        {
            s.push(n);
            visited[n]=true;
            n=edges[n];
        }
        return s;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dist1(n, -1), dist2(n, -1);

    // Helper function to record distances from a starting node
    auto computeDistances = [&](int start, vector<int>& dist) {
        int d = 0;
        while (start != -1 && dist[start] == -1) {
            dist[start] = d++;
            start = edges[start];  // Move to next node
        }
    };

    computeDistances(node1, dist1);
    computeDistances(node2, dist2);

    int result = -1;
    int minDist = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (dist1[i] != -1 && dist2[i] != -1) {
            int maxDist = max(dist1[i], dist2[i]);
            if (maxDist < minDist || (maxDist == minDist && i < result)) {
                result = i;
                minDist = maxDist;
            }
        }
    }

    return result;
}

};









// class Solution {
// public:
//     int closestMeetingNode(vector<int>& edges, int node1, int node2) {
//         unordered_map<int,int>d1;
//         unordered_map<int,int>d2;
//         auto solve=[&](unordered_map<int,int>&d,int n){
//             int dis=1;
//             unordered_map<int,bool>vis;
//             while(!vis[n] && n!=-1)
//             {
//                 d[n]=dis++;
//                 vis[n]=true;
//                 n=edges[n];
//             }
//         };

//         solve(d1,node1);
//         solve(d2,node2);

//         // for(auto&i:d1)
//         // cout<<i.first<<" "<<i.second<<endl;

//         int md=INT_MAX,m,ans=-1;
//         for(auto&i:d1)
//         {
//             if(!d2[i.first])    continue;
//             m=max(i.second,d2[i.first]);
//             if(m<md)
//             {
//                 md=m;
//                 ans=i.first;
//             }
//         }
//         return ans;
//     }
// };
