using p=pair<int,int>;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int>ans(n,1);
        unordered_map<int,queue<int>>ump;// rains[i], queue<pos>
        for(int i=0;i<n;i++)
            ump[rains[i]].push(i);
        
        priority_queue<p,vector<p>,greater<p>>pq;// {next_pos,rains[i](lake num)}
        unordered_map<int,bool>filled;// lake,filled or not

        for(int i=0;i<n;i++)
        {
            if(filled[rains[i]])
            {
                ans.clear();
                break;
            }

            if(rains[i]==0)
            {
                if(pq.empty())  continue;
                auto p=pq.top();
                pq.pop();
                filled[p.second]=false;
                ans[i]=p.second;
            }
            else {
                ump[rains[i]].pop();
                if(!ump[rains[i]].empty())
                    pq.push({ump[rains[i]].front(),rains[i]});
                filled[rains[i]]=true;
                ans[i]=-1;
            }
        }
        return ans;
    }
};
