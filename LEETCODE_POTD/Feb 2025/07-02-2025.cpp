
//  Problem ->  https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/?envType=daily-question&envId=2025-02-07

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>ball,color;
        int distinct=0;
        vector<int>ans;
        for(auto&v:queries)
        {
            if(ball[v[0]])
            {
                color[ball[v[0]]]--;
                if(color[ball[v[0]]]==0) distinct--;
            }
            if(color[v[1]])                distinct--;

            ball[v[0]]=v[1];
            color[v[1]]++;
            distinct++;
            ans.push_back(distinct);
        }
        return ans;
    }
};
