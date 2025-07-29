class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        vector<int>v(s.size(),0);
        unordered_map<char,pair<int,int>>ump;
        v[0]=s[0];
        ump[s[0]]={1,1};
        for(int i=1;i<v.size();i++) 
        {
            v[i]=s[i] + v[i-1];
            if(ump[s[i]].first) ump[s[i]].second=i+1;
            else    ump[s[i]]={i+1,i+1};
        }
        vector<int>ans;
        for(auto i:ump)
        {
            if(i.second.first==i.second.second)   continue;
            int diff=v[i.second.second-2]-v[i.second.first-1];
            if(diff)    ans.push_back(diff);
        }
        return ans;
    }
};
