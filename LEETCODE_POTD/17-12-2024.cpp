// 2182. Construct String With Repeat Limit

struct Compare {
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second; 
        }
        return a.first < b.first; 
    }
};

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,Compare>pq;
        unordered_map<char,int>ump;
        for(char&c:s)   ump[c]++;
        for(auto&i:ump)          pq.push({i.first,i.second});
        string ans="";
        while(!pq.empty())
        {
            auto [c,f]=pq.top();
            pq.pop();
            int m=min(f,repeatLimit);
            ans.append(m,c);
            f-=m;
            if(f)
            {
                if(pq.empty())  break;
                auto [c2,f2]=pq.top();
                pq.pop();
                ans+=c2;
                f2--;
                if(f2)
                pq.push({c2,f2});
                pq.push({c,f});
            }
        }
        return ans;
    }
};
