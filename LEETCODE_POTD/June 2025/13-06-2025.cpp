class Solution {
    void solve(string&s,char k)
    {
        for(int i=0;i<s.size();i++)
            if(s[i]!=k)
            {
                char c=s[i];
                for(;i<s.size();i++)      if(s[i]==c)    s[i]=k;
            }
    }
public:
    int minMaxDifference(int num) {
        string s=to_string(num), mx=s,mn=s;
        solve(mx,'9');
        solve(mn,'0');
        return stoi(mx)-stoi(mn);
    }
};
