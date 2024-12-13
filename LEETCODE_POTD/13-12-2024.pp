// 2593. Find Score of an Array After Marking All Elements

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        long long score=0;
        set<int>st;
        while(!pq.empty())
        {
            pair<int,int>p=pq.top();
            pq.pop();
            if(st.find(p.second)==st.end())
            {
                score+=p.first;
                st.insert(p.second);
            if(p.second-1>=0)   st.insert(p.second-1);
            if(p.second+1<n)    st.insert(p.second+1);
            }            
        }
        return score;
    }
};
